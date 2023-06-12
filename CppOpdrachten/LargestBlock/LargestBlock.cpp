#include <iostream>
#include <vector>

using namespace std;

const int MAXROWS = 100;

vector<int> findLargestBlock(const vector<vector<int>>& m)
{
	int rows = m.size();
    int checkArray[MAXROWS][MAXROWS];
    int maxSize = 0, maxRow = 0, maxCol = 0;

    for (int i = 0; i <= rows; i++)
    {
        checkArray[i][0] = 0;
        checkArray[0][i] = 0;
    }

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= rows; j++)
        {
            if (m[i - 1][j - 1] == 1)
            {
                checkArray[i][j] = min(min(checkArray[i - 1][j], checkArray[i][j - 1]), checkArray[i - 1][j - 1]) + 1;
                if (checkArray[i][j] > maxSize)
                {
                    maxSize = checkArray[i][j];
                    maxRow = i - maxSize;
                    maxCol = j - maxSize;
                }
            }
            else
            {
                checkArray[i][j] = 0;
            }
        }
    }

    return { maxRow, maxCol, maxSize };
}

int main()
{
    int rows;
    cout << "Enter the amount of rows for the matrix\n";
    cin >> rows;

    vector<vector<int>> matrix(rows, vector<int>(rows));
    cout << "Enter the matrix row by row\n";
    for (int i = 0; i < rows; i++)
    {
	    for (int j = 0; j < rows; j++)
	    {
            cin >> matrix[i][j];
	    }
    }

    vector<int> result = findLargestBlock(matrix);

    cout << "Location of the first element in the maximum square submatrix: (" << result[0] << ", " << result[1] << ")\n";
    cout << "Number of rows in the maximum square submatrix: " << result[2] << "\n";
}

