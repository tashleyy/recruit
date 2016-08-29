#pragma once
#include "LinkedList.h"

template <class K, class V>
class HashTable {
	LinkedList<std::pair<K, V>> **data;
	typename LinkedList<std::pair<K, V>>::iterator find(K key);

public:
	HashTable();
	void put(K key, V val);
	V remove(K key);
	V get(K key);
};

#include "../../src/ds/HashTable.cpp"