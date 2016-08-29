#pragma once

template <class T>
class ArrayList {
	T *data = nullptr;
	int capacity = 0;
	int size = 0;

public:
	ArrayList();
	~ArrayList();
	void add(int index, const T &val);
	T remove(int index);
	T& get(int index);
	T& operator[](int index);
	void print() const;
	void reversePrint() const;
};

#include "../../src/ds/ArrayList.cpp"