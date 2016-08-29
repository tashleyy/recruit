#pragma once
#include <vector>

template <class T>
struct Comparator {
	virtual bool operator()(const T &lhs, const T &rhs) = 0;
	virtual ~Comparator() {}
};

template <class T>
class Heap {
	std::vector<T> data;
	int m;
	Comparator<T> *comp;

	void trickleUp(int index);
	void trickleDown(int index);

public:
	Heap(int m, Comparator<T> *comp);
	void insert(const T &val);
	T peek();
	T pop();
};

#include "../../src/ds/Heap.cpp"