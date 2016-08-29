#include <iostream>
#include "../../lib/ds/ArrayList.h"
#include "../../lib/Exceptions.h"
using namespace std;

const unsigned int INITIAL_CAPACITY = 10;

template <class T>
ArrayList<T>::ArrayList() {
	capacity = INITIAL_CAPACITY;
	data = new T[capacity];
}

template <class T>
ArrayList<T>::~ArrayList() {
	delete data;
}

template <class T>
void ArrayList<T>::add(int index, const T &val) {
	if (index < 0 || index > size) {
		return;
	}
	if (size == capacity) {
		T *newData = new T[capacity*2];
		capacity *= 2;
		for (unsigned int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete data;
		data = newData;
	}
	for (unsigned int i = size; i > index; i--) {
		data[i] = data[i-1];
	}
	data[index] = val;
	size++;
}

template <class T>
T ArrayList<T>::remove(int index) {
	if (index < 0 || index > size-1) {
		throw NoSuchElementException();
	}
	T val = data[index];
	for (unsigned int i = index; i < size; i++) {
		data[i] = data[i+1];
	}
	size--;
	return val;
}

template <class T>
T& ArrayList<T>::get(int index) {
	if (index < 0 || index > size-1) {
		throw NoSuchElementException();
	}
	return data[index];
}

template <class T>
T& ArrayList<T>::operator[](int index) {
	return get(index);
}

template <class T>
void ArrayList<T>::print() const {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

template <class T>
void ArrayList<T>::reversePrint() const {
	for (int i = size-1; i >= 0; i--) {
		cout << data[i] << " ";
	}
	cout << endl;
}