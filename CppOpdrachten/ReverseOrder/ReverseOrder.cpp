#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream input_file("Exercise3_8.txt");

	if (!input_file)
	{
		cout << "Error: file does not exist." << endl;
		return 1;
	}

	vector<int> integers;
	int number;

	while (input_file >> number)
	{
		cout << "Adding " << number << " to vector\n";
		integers.insert(integers.begin(), number);
	}

	ofstream output_file("Exercise3_8.txt", ios::trunc);

	for (const int i : integers)
	{
		cout << "Writing " << i << " to file\n";
		output_file << i << " ";
	}

	return 0;
}
