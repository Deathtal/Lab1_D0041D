#pragma once

#include "Stack.h"

class Queue {
protected:
	char* _word;
	size_t _top = 0;
	size_t _bot = 1;
	friend class Stack;
public:
	Queue(size_t s);
	Queue(Stack stack);
	void Push(char character);
	const char& Peek() const;
	bool Pop();
	void operator=(Stack stack);
};