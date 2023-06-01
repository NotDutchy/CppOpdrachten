#include <iostream>
#include <thread>
#include <semaphore>

std::string text;
std::binary_semaphore sem1(0);
std::binary_semaphore sem2(0);
std::binary_semaphore sem3(0);

void Thread1()
{
    // Wacht op resource 1
    sem1.acquire();

    // Schrijf tekst naar de gedeelde variabele
    text += "Hello ";

    // Geef resource 2 vrij
    sem2.release();
}

void Thread2()
{
    // Wacht op resource 2
    sem2.acquire();

    // Schrijf tekst naar de gedeelde variabele
    text += "world ";

    // Geef resource 3 vrij
    sem3.release();
}

void Thread3()
{
    // Wacht op resource 3
    sem3.acquire();

    // Schrijf tekst naar de gedeelde variabele
    text += "from threads!";

    // Geef resource 1 vrij
    sem1.release();
}

int main()
{
    // Start de threads
    std::thread t1(Thread1);
    std::thread t2(Thread2);
    std::thread t3(Thread3);

    // Geef resource 1 vrij om de threads te starten
    sem1.release();

    // Wacht tot alle threads zijn voltooid
    t1.join();
    t2.join();
    t3.join();

    // Toon de resulterende tekst
    std::cout << "Resultaat: " << text << std::endl;

    return 0;
}
