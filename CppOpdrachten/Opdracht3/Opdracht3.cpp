#include <iostream>
#include <string>

using namespace std;
void count(const char s[], int counts[]);

int main()
{
    char s[100];
    int counts[26];
    cout << "Enter a string: " << endl;
    cin.getline(s, 100);

    count(s, counts);
    
    for (int i = 0; i < 26; i++) {
        if (counts[i] == 0) {
            continue;
        }
        char c = 'a' + i;
        cout << c << ": " << counts[i] << " times." << endl;
    }
}

void count(const char s[], int counts[]) {
    for (int i = 0; i < 26; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < strlen(s); i++) {
        char c = tolower(s[i]);
        if (c >= 'a' && c <= 'z') {
            int charIndex = c - 'a';
            counts[charIndex]++;
        }
    }
}