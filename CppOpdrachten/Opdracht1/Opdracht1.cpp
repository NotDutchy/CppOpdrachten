#include <iostream>
#include <vector>
#include "StopWatch.h"
#include <algorithm>

int main()
{
	std::vector<int> numbers(100000);
	for (int i = 0; i < 100000; i++)
	{
		numbers[i] = rand();
	}

	StopWatch stop_watch;
	sort(numbers.begin(), numbers.end());
	stop_watch.stop();

	cout << "Elapsed time for sorting the array was " << stop_watch.getElapsedTime() << " milliseconds\n";
}
