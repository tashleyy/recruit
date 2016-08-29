#pragma once
#include "LinkedList.h"

template <class T>
class Stack : private LinkedList<T> {
public:
	void push(const T &val);
	T pop();
	T& peek();
	bool isEmpty() const;
};

#include "../../src/ds/Stack.cpp"