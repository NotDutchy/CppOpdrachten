#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream input_file("Exercise3_7.txt");

	if (!input_file) {
		cout << "Error: file does not exist." << endl;
		return 1;
	}

	int num;
	int sum = 0;
	double average = 0;
	int product = 1;
	int count = 0;

	while (input_file >> num) {
		sum = sum + num;
		product *= num;
		count++;
	}

	average = static_cast<double> (sum) / count;

	cout << "Sum of integers is: " << sum << endl;
	cout << "Average of integers is: " << average << endl;
	cout << "Product of integers is: " << product << endl;

	return 0;
}


