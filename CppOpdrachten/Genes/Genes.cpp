#include <iostream>

using namespace std;

int main()
{
    string s;
    cout << "Enter a genome string: ";
    cin >> s;


    int i = 0;
    while (i < s.length()) {
        int startIndex = s.find("ATG", i);
        if (startIndex == string::npos) {
            break;
        }
        startIndex += 3;
        string list[] = {
            "TAG",
            "TTA",
            "TGA"
        };
        int endIndex = s.find(list[0], startIndex);
        for (string end : list) {
            int en = s.find(end, startIndex);
            if (en < endIndex && en != string::npos) {
                endIndex = en;
            }
        }
        endIndex += 1;
        if (endIndex == string::npos) {
            cout << "Could not find end index";
            break;
        }

        int length = endIndex - (startIndex);
        string gene = s.substr(startIndex, endIndex - (startIndex));
        if (length % 3 != 0) {
            cout << "Not a multiple of 3: " << gene << endl;
        }
        else {
            cout << "Start: " << startIndex << " End: " << endIndex << endl;
            cout << gene << endl;
        }
        i = endIndex + 3;
    }
}