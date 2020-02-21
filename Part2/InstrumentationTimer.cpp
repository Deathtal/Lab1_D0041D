#include "InstrumentationTimer.h"
#include <iostream>
#include "Instrumentor.h"

InstrumentationTimer::InstrumentationTimer(const char* name) : _name(name) {
	_startTimepoint = std::chrono::high_resolution_clock::now(); // Saves the time of when the constructor is called
}

InstrumentationTimer::~InstrumentationTimer() {
	auto endTimepoint = std::chrono::high_resolution_clock::now(); // Saves the time of when the destructor is called

	Instrumentor::Get().AddDuration(_name, _startTimepoint, endTimepoint); // Send info to Instrumentor
}