#pragma once

template <class T>
struct Node {
	T val;
	Node<T> *next = nullptr;
	Node<T> *prev = nullptr;

	Node(T val);
};

template <class T>
class LinkedList {
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;

public:
	class iterator {
		Node<T> *curr = nullptr;
		iterator(Node<T> *node);
		friend class LinkedList<T>;

	public:
		iterator();
		iterator& operator++();
		const T& operator*() const;
		const T* operator->() const;
		bool operator==(const iterator &other);
		bool operator!=(const iterator &other);
	};

	~LinkedList();
	void pushFront(const T &val);
	void pushBack(const T &val);
	T popFront();
	T popBack();
	T& peekFront();
	T& peekBack();
	int size() const;
	bool isEmpty() const;
	void print() const;
	void reversePrint() const;
	iterator begin() const;
	iterator end() const;
	T remove(const iterator &it);
};

#include "../src/LinkedList.cpp"