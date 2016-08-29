#include "../../lib/ds/Trie.h"
using namespace std;

TrieNode::TrieNode(char val, bool isWord = false) : val(val), isWord(isWord) {}

Trie::Trie() {
	root = new TrieNode('\0');	
}

Trie::~Trie() {
	deleteAll(root);
}

void Trie::deleteAll(TrieNode *node) {
	if (!node) {
		return;
	}
	for (unsigned int i = 0; i < node->children.size(); i++) {
		deleteAll(node->children[i]);
	}
	delete node;
}

void Trie::insert(string s) {
	TrieNode *curr = root;
	for (unsigned int i = 0; i < s.length(); i++) {
		bool foundChild = false;
		for (unsigned int j = 0; j < curr->children.size(); j++) {
			if (curr->children[j]->val == s[i]) {
				foundChild = true;
				curr = curr->children[j];
				break;
			}
		}
		if (!foundChild) {
			while (i < s.length()) {
				TrieNode *newNode;
				if (i == s.length()-1) {
					newNode = new TrieNode(s[i], true);
				} else {
					newNode = new TrieNode(s[i]);
				}
				curr->children.push_back(newNode);
				curr = newNode;
				i++;
			}
		}
	}
}

bool Trie::contains(string s) {
	TrieNode *curr = root;
	for (unsigned int i = 0; i < s.length(); i++) {
		bool foundChild = false;
		for (unsigned int j = 0; j < curr->children.size(); j++) {
			if (curr->children[j]->val == s[i]) {
				foundChild = true;
				curr = curr->children[j];
				break;
			}
		}
		if (!foundChild) {
			return false;
		}
	}
	return curr->isWord;
}

void Trie::printWords() {
	printWords("", root);
}

void Trie::printWords(string prefix, TrieNode *node) {
	if (!node) {
		return;
	}
	if (node->isWord) {
		cout << prefix + node->val << endl;
	}
	for (unsigned int i = 0; i < node->children.size(); i++) {
		printWords(prefix + node->val, node->children[i]);
	}
}