#include "../../lib/ds/Stack.h"
#include "../../lib/Exceptions.h"
using namespace std;

template <class T>
void Stack<T>::push(const T &val) {
	LinkedList<T>::pushFront(val);
}

template <class T>
T Stack<T>::pop() {
	try {
		return LinkedList<T>::popFront();
	} catch (EmptyLinkedListException &e) {
		throw EmptyStackException();
	}
}

template <class T>
T& Stack<T>::peek() {
	try {
		return LinkedList<T>::peekFront();
	} catch (EmptyLinkedListException &e) {
		throw EmptyStackException();
	}
}

template <class T>
bool Stack<T>::isEmpty() const {
	return LinkedList<T>::isEmpty();
}