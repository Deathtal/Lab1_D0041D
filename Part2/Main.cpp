#include "Instrumentor.h"
#include "InstrumentationTimer.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <cstdlib>

Instrumentor Instrumentor::_Instance;

void fillStack(Stack& stack, size_t amount) { // Fills a Stack with an amount of random letters
	InstrumentationTimer timer("Filling"); // Timer for the total time this function was running
	if (rand() > 50) { // About half of the time fill the stack with a palindrome
		for (int i = 0; i < amount; ++i) {
			char c = 'A' + rand() % 26; // Only adds a random capital letter because I don't see what difference it would make if it could add other characters
			stack.Push(c);
		}
	}
	else {
		std::string s;
		for (int i = 0; i < amount / 2; ++i) {
			char c = 'A' + rand() % 26;
			stack.Push(c);
			s.push_back(c);
		}
		if (amount % 2) { // Add a an additional letter in the middle if amount is an odd number
			char c = 'A' + rand() % 26;
			stack.Push(c);
		}
		for (int i = 1; i < amount / 2 + 1; ++i) {
			char c = s[amount / 2 - i];
			stack.Push(c);
		}
	}
}

bool isPalindromeStack(Stack stack) { // Function that test if a Stack contains a palindrome only using Stack
	InstrumentationTimer timer("Stack"); // Timer for the total time this function was running
	Stack sacrificialStackForFindingOutTheSizeOfTheWordRIP = stack; // Using names that explain what an object is for makes the code more understandable and easier to read
	if (!sacrificialStackForFindingOutTheSizeOfTheWordRIP.Pop()) {
		return 1;
	}
	size_t wordSize = 2; // Instead of using a do-while loop and having this at 1 I just put it to 2 and used a normal while loop instead
	while (sacrificialStackForFindingOutTheSizeOfTheWordRIP.Pop()) {
		++wordSize;
	}
	Stack firstHalf; // This will contain the first half of the word in reverse order
	for (size_t i = 0; i < wordSize / 2; ++i) {
		firstHalf.Push(stack.Peek());
		stack.Pop();
	}
	if (wordSize % 2) { // For odd words the middle letter does not effect whether or not it is a palindrome
		stack.Pop();
	}
	for (int i = 0; i < wordSize / 2; ++i) {
		if (firstHalf.Peek() != stack.Peek()) {
			return 0;
		}
		stack.Pop();
		firstHalf.Pop();
	}
	return 1;
}

bool isPalindromeQueueStack(Stack stack) { // Function that test if a Stack contains a palindrome using both Stack and Queue
	InstrumentationTimer timer("Queue + Stack"); // Timer for the total time this function was running
	Queue queue = stack; // Does not give error for Stack = Queue, even though there's no difference for some reason VS complains about Queue = Stack
	while (1) {
		if (stack.Peek() != queue.Peek()) {
			return 0;
		}
		if (!(stack.Pop() && queue.Pop())) {
			return 1;
		}
	}
}

void benchmark(int seed, int32_t amount_of_times, size_t word_size) { // Benchmarks the functions
	InstrumentationTimer timer("Total time");
	std::cout << "Benchmarking...\n";
	srand(seed);
	for (size_t i = 0; i < amount_of_times; ++i) {
		Stack stack(word_size);
		fillStack(stack, word_size);
		if (isPalindromeStack(stack) != isPalindromeQueueStack(stack)) {
			std::cout << "ERROR: isPalindromeStack and isPalindromeQueueStack did not return the same value\nEnding benchmark...\n";
			return;
		}
	}
	std::cout << "Benchmark complete\n";
}

int main() {
	benchmark(3, 1000000, 64);
	Instrumentor::Get().Print();
}