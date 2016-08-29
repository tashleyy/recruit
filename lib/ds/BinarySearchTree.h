#pragma once

template <class K, class V>
struct BinarySearchTreeNode {
	K key;
	V val;
	BinarySearchTreeNode<K, V> *left = nullptr;
	BinarySearchTreeNode<K, V> *right = nullptr;
	BinarySearchTreeNode<K, V> *parent = nullptr;

	BinarySearchTreeNode(K key, V val);
};

template <class K, class V>
class BinarySearchTree {
	BinarySearchTreeNode<K, V> *root = nullptr;

	BinarySearchTreeNode<K, V>* insertHelper(K key, V val, BinarySearchTreeNode<K, V> *curr);
	BinarySearchTreeNode<K, V>* find(K key, BinarySearchTreeNode<K, V> *curr);
	BinarySearchTreeNode<K, V>* getSuccessor(BinarySearchTreeNode<K, V> *node);
	void printPreOrderHelper(BinarySearchTreeNode<K, V> *curr);
	void printInOrderHelper(BinarySearchTreeNode<K, V> *curr);
	void printPostOrderHelper(BinarySearchTreeNode<K, V> *curr);

public:
	void insert(K key, V val);
	V remove(K key);
	V remove(BinarySearchTreeNode<K, V> *node);
	V get(K key);
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
};

#include "../../src/ds/BinarySearchTree.cpp"