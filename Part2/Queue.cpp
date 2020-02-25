#include "Queue.h"

Queue::Queue() {
	_word = new char[64];
}

Queue::Queue(size_t s) {
	_word = new char[s];
}

Queue::Queue(Stack stack) {
	_word = stack._word;
	_top = stack._top;
	_bot = stack._bot;
}

void Queue::Push(char character) {
	_word[_top] = character;
	++_top;
}

const char& Queue::Peek() const {
	return _word[_bot-1];
}

bool Queue::Pop() {
	if (_top <= _bot) {
		return 0;
	}
	++_bot;
	return 1;
}

void Queue::operator=(Stack stack) {
	_word = stack._word;
	_top = stack._top;
	_bot = stack._bot;
}

const size_t Queue::Size() const {
	return _top - _bot + 1;
}