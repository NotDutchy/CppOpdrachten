#include <iostream>
using namespace std;

const int SIZE = 4;
const int ROWS = 3;
double sumColumn(const double m[][SIZE], int rowSize, int columnIndex);

int main()
{
	double m[ROWS][SIZE];
	
	cout << "Enter a 3-by-4 matrix row by row: " << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		double value = sumColumn(m, ROWS, i);
		cout << "Sum of the elements at column " << i << " is " << value << endl;
	}
}

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex) {
	double sum = 0;
	for (int i = 0; i < rowSize; i++) {
		sum += m[i][columnIndex];
	}

	return sum;
}