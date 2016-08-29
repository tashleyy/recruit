#include <iostream>
#include "../../lib/ds/BinarySearchTree.h"
#include "../../lib/Exceptions.h"

template <class K, class V>
BinarySearchTreeNode<K, V>::BinarySearchTreeNode(K key, V val) : key(key), val(val) {}

template <class K, class V>
BinarySearchTreeNode<K, V>* BinarySearchTree<K, V>::insertHelper(K key, V val, BinarySearchTreeNode<K, V> *curr) {
	if (!curr) {
		curr = new BinarySearchTreeNode<K, V>(key, val);
		return curr;
	}
	if (curr->key >= key) {
		curr->left = insertHelper(key, val, curr->left);
		curr->left->parent = curr;
	} else {
		curr->right = insertHelper(key, val, curr->right);
		curr->right->parent = curr;
	}
	return curr;
}

template <class K, class V>
BinarySearchTreeNode<K, V>* BinarySearchTree<K, V>::find(K key, BinarySearchTreeNode<K, V> *curr) {
	if (!curr) {
		return nullptr;
	}
	if (curr->key == key) {
		return curr;
	} else if (curr->key < key) {
		return find(key, curr->right);
	} else {
		return find(key, curr->left);
	}
}

template <class K, class V>
BinarySearchTreeNode<K, V>* BinarySearchTree<K, V>::getSuccessor(BinarySearchTreeNode<K, V> *node) {
	BinarySearchTreeNode<K, V> *successor = nullptr;
	if (node->right) {
		successor = node->right;
		while (successor->left) {
			successor = successor->left;
		}
		return successor;
	}
	while (node) {
		if (node->parent->left == node) {
			successor = node->parent;
			break;
		} else {
			node = node->parent;
		}
	}
	return successor;
}

template <class K, class V>
void BinarySearchTree<K, V>::printPreOrderHelper(BinarySearchTreeNode<K, V> *curr) {
	if (!curr) {
		return;
	}
	cout << curr->val << " ";
	printPreOrderHelper(curr->left);
	printPreOrderHelper(curr->right);
}

template <class K, class V>
void BinarySearchTree<K, V>::printInOrderHelper(BinarySearchTreeNode<K, V> *curr) {
	if (!curr) {
		return;
	}
	printInOrderHelper(curr->left);
	cout << curr->val << " ";
	printInOrderHelper(curr->right);
}

template <class K, class V>
void BinarySearchTree<K, V>::printPostOrderHelper(BinarySearchTreeNode<K, V> *curr) {
	if (!curr) {
		return;
	}
	printPostOrderHelper(curr->left);
	printPostOrderHelper(curr->right);
	cout << curr->val << " ";
}

template <class K, class V>
void BinarySearchTree<K, V>::insert(K key, V val) {
	root = insertHelper(key, val, root);
}

template <class K, class V>
V BinarySearchTree<K, V>::remove(K key) {
	BinarySearchTreeNode<K, V> *node = find(key, root);
	if (!node) {
		throw NoSuchElementException();
	}
	return remove(node);
}

template <class K, class V>
V BinarySearchTree<K, V>::remove(BinarySearchTreeNode<K, V> *node) {
	BinarySearchTreeNode<K, V> *parent = node->parent;
	bool isLeftChild = parent && parent->left == node;
	bool isRightChild = parent && parent->right == node;

	if (!node->left && !node->right) {
		if (isLeftChild) {
			parent->left = nullptr;
		} else if (isRightChild) {
			parent->right = nullptr;
		} else {
			root = nullptr;
		}
		V val = node->val;
		delete node;
		return val;
	} else if (!node->left || !node->right) {
		if (isLeftChild) {
			parent->left = node->left ? node->left : node->right;
			parent->left->parent = parent;
		} else if (isRightChild) {
			parent->right = node->left ? node->left : node->right;
			parent->right->parent = parent;
		} else {
			root = node->left ? node->left : node->right;
			root->parent = nullptr;
		}
		V val = node->val;
		delete node;
		return val;
	} else {
		BinarySearchTreeNode<K, V> *successor = getSuccessor(node);
		V val = node->val;
		node->key = successor->key;
		node->val = successor->val;
		remove(successor);
		return val;
	}
}

template <class K, class V>
V BinarySearchTree<K, V>::get(K key) {
	BinarySearchTreeNode<K, V> *node = find(key, root);
	if (node) {
		return node->val;
	}
	throw NoSuchElementException();
}

template <class K, class V>
void BinarySearchTree<K, V>::printPreOrder() {
	printPreOrderHelper(root);
	cout << endl;
}

template <class K, class V>
void BinarySearchTree<K, V>::printInOrder() {
	printInOrderHelper(root);
	cout << endl;
}

template <class K, class V>
void BinarySearchTree<K, V>::printPostOrder() {
	printPostOrderHelper(root);
	cout << endl;
}