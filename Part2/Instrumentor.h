#pragma once
#include <map>
#include <iostream>
#include <chrono>

// Singleton class for combining all the durations sent by the InstrumentationTimers
class Instrumentor {
private:
	Instrumentor();
	static Instrumentor _Instance;
	std::map<std::string, long long> _durations;
public:
	static Instrumentor& Get();	
	void AddDuration(const std::string name, std::chrono::time_point<std::chrono::high_resolution_clock> start, std::chrono::time_point<std::chrono::high_resolution_clock> end);
	void Print();
};