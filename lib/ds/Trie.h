#pragma once
#include <vector>

struct TrieNode {
	char val;
	std::vector<TrieNode*> children;
	bool isWord;

	TrieNode(char val, bool isWord);
};

class Trie {
	TrieNode *root;

	void deleteAll(TrieNode *node);
	void printWords(std::string prefix, TrieNode *node);

public:
	Trie();
	~Trie();
	void insert(std::string s);
	bool contains(std::string s);
	void printWords();
};

#include "../../src/ds/Trie.cpp"