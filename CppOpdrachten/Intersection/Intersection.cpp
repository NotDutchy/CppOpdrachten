

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
std::vector<T> intersect(const std::vector<T>& v1, const std::vector<T>& v2)
{
    vector<T> commonElements;

    for (int i = 0; i < v1.size(); i++)
    {
	    for (int j = 0; j < v2.size(); j++)
	    {
		    if (v1[i] == v2[j])
		    {
				commonElements.push_back(v1[i]);
		    }
	    }
    }
    return commonElements;
}

int main()
{
    const vector<int> list1 = { 10,11,12,13,14 };

    const vector<int> list2 = { 20,11,12,24 };

    const vector<string> stringList1 = {"Merijn", "Richard","Guus", "Xander", "Owen"};
    const vector<string> stringList2 = { "Richard", "Guus", "Owen Verhoeven", "Jasper", "Momin"};

    vector<int> intersections = intersect<int>(list1, list2);
    vector<string> commonStrings = intersect<string>(stringList1, stringList2);

    for (int i = 0; i < intersections.size(); i++) {
        cout << "Value: " << intersections[i] << endl;
    }

    for (int i = 0; i < commonStrings.size(); i++) {
        cout << "Value: " << commonStrings[i] << endl;
    }
}