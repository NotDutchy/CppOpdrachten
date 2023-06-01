/*
 
De 3-5-0-regel (ook bekend als de Regel van Drie/Vijf/Nul) in C++ biedt richtlijnen voor het beheren van resources en het waarborgen van correct gedrag en resource-opruiming in je C++-code. Hier zijn enkele redenen waarom je deze regel zou gebruiken:

Correct resourcebeheer: Door de 3-5-0-regel te volgen, zorg je ervoor dat resources, zoals dynamisch toegewezen geheugen of externe handles, op de juiste manier worden beheerd. Het voorkomt geheugenlekken, resourcelekken en andere problemen die kunnen ontstaan bij handmatig resourcebeheer.

Voorkomen van dubbele verwijdering: Als je klasse dynamisch toegewezen resources beheert, zoals geheugen toegewezen met new, zorgt het volgen van de regel ervoor dat de destructor, kopieconstructor en kopie-toekenningsoperator de resource-eigendom correct afhandelen. Dit helpt dubbele verwijderingsproblemen te voorkomen waarbij dezelfde resource meerdere keren wordt vrijgegeven.

Consistent gedrag bij kopiëren en toewijzen: Door de juiste constructoren en toekenningsoperators te implementeren, zorg je ervoor dat het kopiëren of toewijzen van instanties van je klasse zich gedraagt zoals verwacht. Dit is met name belangrijk als je klasse pointers bevat of andere resources beheert die correct gedupliceerd of gedeeld moeten worden.

Wat kan er fout gaan als ik de regel niet gebruik?

Het niet toepassen van de 3-5-0-regel kan leiden tot resourcelekken, dubbele verwijdering, onverwacht gedrag, prestatieproblemen en complexiteit in je code.
Door de regel te volgen, kun je deze potentiële problemen vermijden en zorgen voor correct en efficiënt resourcebeheer in je C++-programma's.
*/

#include <iostream>

class ThreeFiveZero
{
private:
	int* data;
	int size;

public:
	//Constructor
	ThreeFiveZero(int sz) : size(sz)
	{
		data = new int[size];
	}

	// Destructor
	~ThreeFiveZero()
	{
		delete[] data;
	}

	//Copy constructor
	ThreeFiveZero(const ThreeFiveZero& other) : size(other.size)
	{
		data = new int[size];
		std::copy(other.data, other.data + size, data);
	}

	//Copy Assignment operator
	ThreeFiveZero& operator=(const ThreeFiveZero& other)
	{
		if (this != &other)
		{
			delete[] data;
			size = other.size;
			data = new int[size];
			std::copy(other.data, other.data + size, data);
		}
		return *this;
	}

	// Print de data van het object
	void printData() const
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	ThreeFiveZero testObj(5);

	for (int i = 0; i < 5; i++)
	{
		testObj.printData();
		testObj = ThreeFiveZero(9);
		testObj.printData();
	}
	return 0;
}