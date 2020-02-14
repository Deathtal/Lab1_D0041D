#include "InstrumentationTimer.h"
#include <iostream>

InstrumentationTimer::InstrumentationTimer(const char* name) : _name(name) {
	_startTimepoint = std::chrono::high_resolution_clock::now(); // Saves the time of when the constructor is called
}

InstrumentationTimer::~InstrumentationTimer() {
	auto endTimepoint = std::chrono::high_resolution_clock::now(); // Saves the time of when the destructor is called
	long long duration = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimepoint).time_since_epoch().count() - std::chrono::time_point_cast<std::chrono::milliseconds>(_startTimepoint).time_since_epoch().count(); // Calculates the time between when the constructor was called and when the destructor was called

	std::cout << _name << ": " << duration << "ms\n";
}