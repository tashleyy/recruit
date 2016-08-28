#include "../lib/Heap.h"
#include "../lib/Exceptions.h"

template <class T>
Heap<T>::Heap(int m, Comparator<T> *comp) : m(m), comp(comp) {}

template <class T>
void Heap<T>::trickleUp(int index) {
	if ((*comp)(data[index], data[(index-1)/m])) {
		T temp = data[index];
		data[index] = data[(index-1)/m];
		data[(index-1)/m] = temp;
		trickleUp((index-1)/m);
	}
}

template <class T>
void Heap<T>::trickleDown(int index) {
	if (index >= data.size()) {
		return;
	}
	int toppest = index*m+1;
	for (int i = index*m+2; (i <= index*m+m) && (i < data.size()); i++) {
		if ((*comp)(data[i], data[toppest])) {
			toppest = i;
		}
	}
	if (toppest < data.size() && (*comp)(data[toppest], data[index])) {
		T temp = data[toppest];
		data[toppest] = data[index];
		data[index] = temp;
		trickleDown(toppest);
	}
}

template <class T>
void Heap<T>::insert(const T &val) {
	data.push_back(val);
	trickleUp(data.size()-1);
}

template <class T>
T Heap<T>::peek() {
	if (data.size() == 0) {
		throw NoSuchElementException();
	}
	return data[0];
}

template <class T>
T Heap<T>::pop() {
	if (data.size() == 0) {
		throw NoSuchElementException();
	}
	T val = data[0];
	data[0] = data[data.size()-1];
	data.pop_back();
	trickleDown(0);
	return val;
}