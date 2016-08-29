#pragma once
#include "LinkedList.h"

template <class T>
class Queue : private LinkedList<T> {
public:
	void add(const T &val);
	T remove();
	T& peek();
	bool isEmpty() const;
};

#include "../../src/ds/Queue.cpp"