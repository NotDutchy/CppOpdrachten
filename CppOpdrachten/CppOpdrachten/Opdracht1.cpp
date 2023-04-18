#include <iostream>
#include <string>

using namespace std;
bool search(string& s, char& key);

int main()
{
    string s;
    char key;
    cout << "Enter a string: " << endl;
    getline(cin, s);

    cout << "Enter a character to search for within the string: " << endl;
    cin >> key;

    if (search(s, key)) {
        cout << "Character " << key << " was found in " << s << endl;
    }
    else {
        cout << "Character " << key << " was not found in " << s << endl;
    }
}

bool search(string& s, char& key) {
    for (char c : s) {
        if (c == key) {
            return true;
        }
    }
    return false;
}