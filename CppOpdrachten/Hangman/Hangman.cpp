#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;


bool checkLetter(const string& wordToGuess, const char letter)
{
	return wordToGuess.find(letter) != string::npos;
}

bool containsLetter(const list<char> &letters, const char letter)
{
	return find(letters.begin(), letters.end(), letter) != letters.end();
}

void print(const string& wordToGuess, const list<char> &letters)
{
	for (const char c : wordToGuess)
	{
		if (containsLetter(letters, c))
		{
			cout << c;
		}
		else
		{
			cout << "*";
		}
	}
}

bool checkWin(const list<char> &letters, const string &word)
{
	for (const char c : word)
	{
		if (!containsLetter(letters, c))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	bool guessed = false;
	int missed = 0;
	vector<string> words = {"write", "that", "school", "merijn", "guus", "xander", "tommy"};
	list<char> letters = {};

	srand(time(NULL));

	int index = rand() % words.size();

	cout << index << "\n";

	string wordToGuess = words[index];

	while (!guessed)
	{
		cout << "Enter a letter in the word ";
		print(wordToGuess, letters);
		cout << ": ";

		char letter;
		cin >> letter;

		if (!containsLetter(letters, letter))
		{
			if (!checkLetter(wordToGuess, letter))
			{
				missed++;
			}
			letters.push_back(letter);
		}

		if (checkWin(letters, wordToGuess))
		{
			cout << "The word was " << wordToGuess << "! You had " << missed << " misses.\n";
			guessed = true;
		}
	}
}