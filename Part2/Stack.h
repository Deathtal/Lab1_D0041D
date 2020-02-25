#pragma once

#include "Queue.h"

class Stack {
protected:
	char* _word;
	size_t _top = 0;
	size_t _bot = 1;
	friend class Queue;
public:
	Stack();
	Stack(size_t s);
	Stack(Queue queue);
	void Push(char character);
	const char& Peek() const;
	bool Pop();
	void operator=(Queue queue);
	const size_t Size() const;
};