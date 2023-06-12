#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void intersect(vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (v[i] == v[j] && j != i)
			{
				v.erase(v.begin() + j - 1);
			}
		}
	}
}


int main()
{
	vector<int> list = { 20,11,12,24,20, 90, 100, 25, 24 };

	intersect<int>(list);

    for (int i = 0; i < list.size(); i ++)
    {
		cout << list[i] << endl;
    }
}
