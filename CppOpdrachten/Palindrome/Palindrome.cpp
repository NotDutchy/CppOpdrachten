#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& s);

int main()
{
	string s;

	cout << "Enter a string\n";
	cin >> s;

	if (isPalindrome(s))
	{
		cout << s << " is a palindrome\n";
	} else
	{
		cout << s << " is not a palindrome\n";
	}
}

bool isPalindrome(const string& s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (tolower(s[i]) == tolower(s[s.length() - 1 - i]))
		{
			continue;
		} else
		{
			return false;
		}
	}
	return true;
}
