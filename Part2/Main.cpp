#include "InstrumentationTimer.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <string>

std::string randomWord(size_t size) {
	std::string string;
	for (int i = 0; i < size; ++i) {
		string[i] = 'A' + rand() % 26;
	}
}

int main() {
	Stack a(64);

	do {
		
	} while (b.Pop());
}