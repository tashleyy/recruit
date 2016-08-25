#include <iostream>
#include "../lib/LinkedList.h"
#include "../lib/Exceptions.h"
using namespace std;

template <class T>
Node<T>::Node(T val) : val(val) {}

template <class T>
LinkedList<T>::iterator::iterator() {}

template <class T>
LinkedList<T>::iterator::iterator(Node<T> *node) {
	curr = node;
}

template <class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++() {
	curr = curr->next;
	return *this;
}

template <class T>
const T& LinkedList<T>::iterator::operator*() const {
	return curr->val;
}

template <class T>
const T* LinkedList<T>::iterator::operator->() const {
	return &(curr->val);
}

template <class T>
bool LinkedList<T>::iterator::operator==(const iterator &other) {
	return this->curr == other.curr;
}

template <class T>
bool LinkedList<T>::iterator::operator!=(const iterator &other) {
	return !(*this == other);
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (!isEmpty()) {
		popFront();
	}
}

template <class T>
void LinkedList<T>::pushFront(const T &val) {
	if (head) {
		Node<T> *newNode = new Node<T>(val);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	}
	head = new Node<T>(val);
	tail = head;
}

template <class T>
void LinkedList<T>::pushBack(const T &val) {
	if (tail) {
		Node<T> *newNode = new Node<T>(val);
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		return;
	}
	tail = new Node<T>(val);
	head = tail;
}

template <class T>
T LinkedList<T>::popFront() {
	if (!head) {
		throw EmptyLinkedListException();
	}
	T val = head->val;
	if (head->next) {
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	} else {
		delete head;
		head = tail = nullptr;
	}
	return val;
}

template <class T>
T LinkedList<T>::popBack() {
	if (!tail) {
		throw EmptyLinkedListException();
	}
	T val = tail->val;
	if (tail->prev) {
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	} else {
		delete tail;
		tail = head = nullptr;
	}
	return val;
}

template <class T>
T& LinkedList<T>::peekFront() {
	if (!head) {
		throw EmptyLinkedListException();
	}
	return head->val;
}

template <class T>
T& LinkedList<T>::peekBack() {
	if (!tail) {
		throw EmptyLinkedListException();
	}
	return tail->val;
}

template <class T>
int LinkedList<T>::size() const {
	int size = 0;
	Node<T> *curr = head;
	while (curr) {
		size++;
		curr = curr->next;
	}
	return size;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
	return head == nullptr;
}

template <class T>
void LinkedList<T>::print() const {
	Node<T> *curr = head;
	while (curr) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}

template <class T>
void LinkedList<T>::reversePrint() const {
	Node<T> *curr = tail;
	while (curr) {
		cout << curr->val << " ";
		curr = curr->prev;
	}
	cout << endl;
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() const {
	return iterator(head);
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::end() const {
	return iterator(nullptr);
}

template <class T>
T LinkedList<T>::remove(const LinkedList<T>::iterator &it) {
	Node<T> *rem = it.curr;
	if (rem->prev) {
		rem->prev->next = rem->next;
	} else {
		head = rem->next;
	}
	if (rem->next) {
		rem->next->prev = rem->prev;
	} else {
		tail = rem->prev;
	}
	T val = rem->val;
	delete rem;
	return val;
}