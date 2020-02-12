#pragma once

#include <chrono>

class InstrumentationTimer {
private:
	const char* _name;
	std::chrono::time_point<std::chrono::high_resolution_clock> _startTimepoint;
public:
	InstrumentationTimer(const char* name);
	~InstrumentationTimer();
};