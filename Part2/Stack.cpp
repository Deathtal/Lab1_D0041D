#include "Stack.h"

Stack::Stack() {
	_word = new char[64];
}

Stack::Stack(size_t s) {
	_word = new char[s];
}

Stack::Stack(Queue queue) {
	_word = queue._word;
	_top = queue._top;
	_bot = queue._bot;
}

void Stack::Push(char character) {
	_word[_top] = character;
	++_top;
}

const char& Stack::Peek() const {
	return _word[_top-1];
}

bool Stack::Pop() {
	if (_top <= _bot) {
		return 0;
	}
	--_top;
	return 1;
}

void Stack::operator=(Queue queue) {
	_word = queue._word;
	_top = queue._top;
	_bot = queue._bot;
}