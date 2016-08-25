#include <functional>
#include "../lib/HashTable.h"
#include "../lib/Exceptions.h"
using namespace std;

const int NUM_BUCKETS = 20;

template <class K, class V>
HashTable<K, V>::HashTable() {
	data = new LinkedList<pair<K, V>>*[NUM_BUCKETS];
	for (unsigned int i = 0; i < NUM_BUCKETS; i++) {
		data[i] = new LinkedList<pair<K, V>>;
	}
}

template <class K, class V>
V HashTable<K, V>::put(K key, V val) {
	size_t keyHash = hash<K>{}(key);
	try {
		return find(key)->second;
	} catch (NoSuchElementException &e) {
		data[keyHash%NUM_BUCKETS]->pushBack(make_pair(key, val));		
		return val;
	}
}

template <class K, class V>
V HashTable<K, V>::remove(K key) {
	size_t keyHash = hash<K>{}(key);
	LinkedList<pair<K, V>> *linkedList = data[keyHash%NUM_BUCKETS];
	return linkedList->remove(find(key)).second;
}

template <class K, class V>
V HashTable<K, V>::get(K key) {
	return find(key)->second;
}

template <class K, class V>
typename LinkedList<pair<K, V>>::iterator HashTable<K, V>::find(K key) {
	size_t keyHash = hash<K>{}(key);
	LinkedList<pair<K, V>> *linkedList = data[keyHash%NUM_BUCKETS];
	for (typename LinkedList<pair<K, V>>::iterator it = linkedList->begin(); it != linkedList->end(); ++it) {
		if (it->first == key) {
			return it;
		}
	}
	throw NoSuchElementException();	
}