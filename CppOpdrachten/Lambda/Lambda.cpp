#include <iostream>
#include <functional>
#include <vector>

typedef std::function<int()> MyTypeFunc;

MyTypeFunc sumLambda(const std::vector<int>& numbers)
{
	return [&numbers]()
	{
		int sum = 0;
		for (int num : numbers)
		{
			sum += num;
		}
		return sum;
	};
}

int main()
{
	std::vector<int> numbers = { 10, 32, 13, 45, 85 };

	MyTypeFunc myLambda = sumLambda(numbers);
	int result = myLambda();

    std::cout << "Result: " << result << std::endl;

	return 0;
}