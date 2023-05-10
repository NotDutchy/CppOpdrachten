#include <iostream>
#include <fstream>

using namespace std;

int main() {

    cout << "Enter a filename: \n";
    string fileName;
    cin >> fileName;

    ifstream input_file(fileName);

    if (!input_file) {
        cout << "Error: file does not exist." << endl;
        return 1;
    }

    int count = 0;
    char c;
    while (input_file.get(c)) {
	    if (c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i' || c == 'y')
	    {
            ++count;
	    }
    }

    cout << "Total number of vowels in file: " << count << endl;

    return 0;
}