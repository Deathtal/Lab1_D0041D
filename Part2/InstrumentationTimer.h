#pragma once

#include <chrono>

// Class for benchmarking the time between it's creasion and when it goes out of scope

class InstrumentationTimer {
private:
	const char* _name;
	std::chrono::time_point<std::chrono::high_resolution_clock> _startTimepoint;
public:
	InstrumentationTimer(const char* name);
	~InstrumentationTimer();
};