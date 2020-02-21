#include "Instrumentor.h"


Instrumentor::Instrumentor() {}

Instrumentor& Instrumentor::Get() {
	return _Instance;
}

void Instrumentor::AddDuration(const std::string name, std::chrono::time_point<std::chrono::high_resolution_clock> start, std::chrono::time_point<std::chrono::high_resolution_clock> end) {
	long long duration = std::chrono::time_point_cast<std::chrono::nanoseconds>(end).time_since_epoch().count() - std::chrono::time_point_cast<std::chrono::nanoseconds>(start).time_since_epoch().count(); // Calculates the time between start and end in nanoseconds (not using a high enough of a resolution of time results in errors stacking up over time)

	if (_durations.find(name) != _durations.end()) { // Saves the duration taken to an existing key if it can or a new one
		_durations[name] = _durations.find(name)->second + duration;
	}
	else {
		_durations[name] = duration;
	}
}

void Instrumentor::Print() { // Prints out all keys and thier values
	for (auto i = _durations.cbegin(); i != _durations.cend(); ++i) {
		std::cout << i->first << ": " << i->second/1000000.0 << " ms\n";
	}
}