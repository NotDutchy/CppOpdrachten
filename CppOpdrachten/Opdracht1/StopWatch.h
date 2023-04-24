#pragma once
#include <chrono>

using namespace std::chrono;
using namespace std;

class StopWatch {

	private:
		time_point<steady_clock> startTime;
		time_point<steady_clock> endTime;

	public:	
		StopWatch()
		{
			start();
		}

		void start()
		{
			startTime = steady_clock::now();
		}

		void stop()
		{
			endTime = steady_clock::now();
		}

		long long getElapsedTime()
		{
			return duration_cast<milliseconds>(endTime - startTime).count();

		}
};

