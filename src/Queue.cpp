#include "../lib/Queue.h"
#include "../lib/Exceptions.h"
using namespace std;

template <class T>
void Queue<T>::add(const T &val) {
	LinkedList<T>::pushBack(val);
}

template <class T>
T Queue<T>::remove() {
	try {
		return LinkedList<T>::popFront();
	} catch (EmptyLinkedListException &e) {
		throw EmptyQueueException();
	}
}

template <class T>
T& Queue<T>::peek() {
	try {
		return LinkedList<T>::peekFront();
	} catch (EmptyLinkedListException &e) {
		throw EmptyQueueException();
	}
}

template <class T>
bool Queue<T>::isEmpty() const {
	return LinkedList<T>::isEmpty();
}