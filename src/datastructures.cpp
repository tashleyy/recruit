#include <iostream>
#include "../lib/LinkedList.h"
#include "../lib/Stack.h"
#include "../lib/Queue.h"
#include "../lib/ArrayList.h"
#include "../lib/HashTable.h"
#include "../lib/BinarySearchTree.h"
#include "../lib/Heap.h"
#include "../lib/Trie.h"
#include "../lib/Exceptions.h"
using namespace std;

void testLinkedList();
void testStack();
void testQueue();
void testArrayList();
void testHashTable();
void testBinarySearchTree();
void testHeap();
void testTrie();

int main(int argc, char **argv) {
	// TESTS ARE NOT EXTENSIVE/COMPREHENSIVE
	testLinkedList();
	testStack();
	testQueue();
	testArrayList();
	testHashTable();
	testBinarySearchTree();
	testHeap();
	testTrie();
	return 0;
}

void testLinkedList() {
	cout << "TESTING LINKED LIST" << endl;
	LinkedList<int> linkedList;
	cout << "List: ";
	linkedList.print();

	linkedList.pushFront(1);
	cout << "Pushed front 1" << endl;
	cout << "List: ";
	linkedList.print();
	cout << "Reverse list: ";
	linkedList.reversePrint();

	linkedList.pushFront(2);
	cout << "Pushed front 2" << endl;
	cout << "List: ";
	linkedList.print();
	cout << "Reverse list: ";
	linkedList.reversePrint();

	cout << "Pop front " << linkedList.popFront() << endl;
	cout << "List: ";
	linkedList.print();
	cout << "Reverse list: ";
	linkedList.reversePrint();

	cout << "Pop back " << linkedList.popBack() << endl;
	cout << "List: ";
	linkedList.print();
	cout << "Reverse list: ";
	linkedList.reversePrint();
	cout << endl;
}

void testStack() {
	cout << "TESTING STACK" << endl;
	Stack<string> stack;
	try {
		stack.peek();
	} catch (EmptyStackException &e) {
		cout << "Caught EmptyStackException" << endl;
	}
	cout << "Stack is empty: " << stack.isEmpty() << endl;
	stack.push("aa");
	cout << "Pushed aa" << endl;
	cout << "Stack is empty: " << stack.isEmpty() << endl;
	cout << "Peeked " << stack.peek() << endl;
	stack.push("bb");
	cout << "Pushed bb" << endl;
	cout << "Peeked " << stack.peek() << endl;
	cout << "Popped " << stack.pop() << endl;
	cout << "Peeked " << stack.peek() << endl;
	cout << "Popped " << stack.pop() << endl;
	try {
		stack.pop();
	} catch (EmptyStackException &e) {
		cout << "Caught EmptyStackException" << endl;
	}
	cout << "Stack is empty: " << stack.isEmpty() << endl;
	cout << endl;
}

void testQueue() {
	cout << "TESTING QUEUE" << endl;
	Queue<char> queue;
	try {
		queue.peek();
	} catch (EmptyQueueException &e) {
		cout << "Caught EmptyQueueException" << endl;
	}
	cout << "Queue is empty: " << queue.isEmpty() << endl;
	queue.add('a');
	cout << "Added a" << endl;
	cout << "Queue is empty: "  << queue.isEmpty() << endl;
	cout << "Peeked " << queue.peek() << endl;
	queue.add('b');
	cout << "Added b" << endl;
	cout << "Peeked " << queue.peek() << endl;
	cout << "Removed " << queue.remove() << endl;
	cout << "Peeked " << queue.peek() << endl;
	cout << "Removed " << queue.remove() << endl;
	try {
		queue.peek();
	} catch (EmptyQueueException &e) {
		cout << "Caught EmptyQueueException" << endl;
	}
	cout << "Queue is empty: "  << queue.isEmpty() << endl;
	cout << endl;
}

void testArrayList() {
	cout << "TESTING ARRAY LIST" << endl;
	ArrayList<int> arrayList;
	cout << "List: ";
	arrayList.print();

	arrayList.add(0, 1);
	cout << "Added 1 to index 0" << endl;
	cout << "List: ";
	arrayList.print();
	cout << "Reverse list: ";
	arrayList.reversePrint();

	arrayList.add(1, 2);
	cout << "Added 2 to index 1" << endl;
	cout << "List: ";
	arrayList.print();
	cout << "Reverse list: ";
	arrayList.reversePrint();

	arrayList.add(3, 3);
	cout << "Failed to add 3 to index 3" << endl;
	cout << "List: ";
	arrayList.print();
	cout << "Reverse list: ";
	arrayList.reversePrint();	

	cout << "Removed " << arrayList.remove(0) << " from index 0" << endl;
	cout << "List: ";
	arrayList.print();
	cout << "Reverse list: ";
	arrayList.reversePrint();

	cout << "Removed " << arrayList.remove(0) << " from index 0" << endl;
	cout << "List: ";
	arrayList.print();
	cout << "Reverse list: ";
	arrayList.reversePrint();

	try {
		arrayList[0];
	} catch (NoSuchElementException &e) {
		cout << "Caught NoSuchElementException" << endl;
	}

	arrayList.add(0, 4);
	cout << "Added 4 to index 0" << endl;
	cout << "List: ";
	arrayList.print();
	cout << "Reverse list: ";
	arrayList.reversePrint();
	cout << "arrayList[0] = " << arrayList[0] << endl;

	try {
		arrayList.remove(-1);
	} catch (NoSuchElementException &e) {
		cout << "Caught NoSuchElementException" << endl;		
	}

	cout << "Removed " << arrayList.remove(0) << " from index 0" << endl;
	cout << "List: ";
	arrayList.print();
	cout << "Reverse list: ";
	arrayList.reversePrint();

	cout << "Adding 20 elements" << endl;
	for (int i = 0; i < 20; i++) {
		arrayList.add(0, i);
		cout << "List: ";
		arrayList.print();
		cout << "Reverse list: ";
		arrayList.reversePrint();
	}
	cout << endl;
}

void testHashTable() {
	cout << "TESTING HASH TABLE" << endl;
	HashTable<char, int> hashTable;
	for (int i = 0; i < 26; i++) {
		hashTable.put('a'+i, i+1);
		cout << "Put (" << static_cast<char>('a'+i) << ", " << i+1 << ")" << endl;
	}
	for (int i = 25; i >= 0; i--) {
		cout << "Removed (" << static_cast<char>('a'+i) << ", " << hashTable.remove('a'+i) << ")" << endl;
	}
	try {
		hashTable.get('a');
	} catch (NoSuchElementException &e) {
		cout << "Caught NoSuchElementException" << endl;
	}
	hashTable.put('a', 1);
	cout << "Put (a, 1)" << endl;
	hashTable.put('a', 2);
	cout << "Put (a, 2)" << endl;	
	cout << "Got (a, " << hashTable.get('a') << ")" << endl;
	cout << endl;
}

void testBinarySearchTree() {
	cout << "TESTING BINARY SEARCH TREE" << endl;
	BinarySearchTree<int, int> binarySearchTree;
	Stack<int> stack;
	srand(time(0));
	for (int i = 0; i < 15; i++) {
		int n = rand() % 15;
		stack.push(n);
		binarySearchTree.insert(n, n);
		cout << "Inserted (" << n << ", "<< n << ")" << endl;
	}
	cout << "Pre order: ";
	binarySearchTree.printPreOrder();
	cout << "In order: ";
	binarySearchTree.printInOrder();
	cout << "Post order: ";
	binarySearchTree.printPostOrder();
	while (!stack.isEmpty()) {
		cout << "Removed " << binarySearchTree.remove(stack.pop()) << endl;
		cout << "Pre order: ";
		binarySearchTree.printPreOrder();
	}
	try {
		binarySearchTree.remove(1);
	} catch (NoSuchElementException &e) {
		cout << "Caught NoSuchElementException" << endl;
	}
	cout << endl;
}

template <class T>
struct LessThanComp : public Comparator<T> {
	bool operator()(const T &lhs, const T &rhs) {
		return lhs < rhs;
	}
	~LessThanComp() {}
};

template <class T>
struct GreaterThanComp : public Comparator<T> {
	bool operator()(const T &lhs, const T &rhs) {
		return lhs > rhs;
	}
	~GreaterThanComp() {}
};

void testHeap() {
	cout << "TESTING HEAP" << endl;
	Comparator<int> *ltc = new LessThanComp<int>();
	Comparator<int> *gtc = new GreaterThanComp<int>();
	Heap<int> minHeap = Heap<int>(3, ltc);
	Heap<int> maxHeap = Heap<int>(3, gtc);
	minHeap.insert(1);
	cout << "Inserted 1 into minHeap" << endl;
	maxHeap.insert(1);
	cout << "Inserted 1 into maxHeap" << endl;
	cout << "Peeked " << minHeap.peek() << " from minHeap" << endl;
	cout << "Peeked " << maxHeap.peek() << " from maxHeap" << endl;
	minHeap.insert(2);
	cout << "Inserted 2 into minHeap" << endl;
	maxHeap.insert(2);
	cout << "Inserted 2 into maxHeap" << endl;
	cout << "Peeked " << minHeap.peek() << " from minHeap" << endl;
	cout << "Peeked " << maxHeap.peek() << " from maxHeap" << endl;
	minHeap.insert(4);
	cout << "Inserted 4 into minHeap" << endl;
	maxHeap.insert(4);
	cout << "Inserted 4 into maxHeap" << endl;
	cout << "Peeked " << minHeap.peek() << " from minHeap" << endl;
	cout << "Peeked " << maxHeap.peek() << " from maxHeap" << endl;
	minHeap.insert(3);
	cout << "Inserted 3 into minHeap" << endl;
	maxHeap.insert(3);
	cout << "Inserted 3 into maxHeap" << endl;
	cout << "Peeked " << minHeap.peek() << " from minHeap" << endl;
	cout << "Peeked " << maxHeap.peek() << " from maxHeap" << endl;
	minHeap.insert(-1);
	cout << "Inserted -1 into minHeap" << endl;
	maxHeap.insert(-1);
	cout << "Inserted -1 into maxHeap" << endl;
	cout << "Peeked " << minHeap.peek() << " from minHeap" << endl;
	cout << "Peeked " << maxHeap.peek() << " from maxHeap" << endl;
	cout << "Popped " << minHeap.pop() << " from minHeap" << endl;
	cout << "Popped " << maxHeap.pop() << " from maxHeap" << endl;
	cout << "Peeked " << minHeap.peek() << " from minHeap" << endl;
	cout << "Peeked " << maxHeap.peek() << " from maxHeap" << endl;
	minHeap.insert(2);
	cout << "Inserted 2 into minHeap" << endl;
	maxHeap.insert(2);
	cout << "Inserted 2 into maxHeap" << endl;
	cout << "Peeked " << minHeap.peek() << " from minHeap" << endl;
	cout << "Peeked " << maxHeap.peek() << " from maxHeap" << endl;
	cout << "Popped " << minHeap.pop() << " from minHeap" << endl;
	cout << "Popped " << maxHeap.pop() << " from maxHeap" << endl;
	cout << "Peeked " << minHeap.peek() << " from minHeap" << endl;
	cout << "Peeked " << maxHeap.peek() << " from maxHeap" << endl;
	cout << "Popped " << minHeap.pop() << " from minHeap" << endl;
	cout << "Popped " << maxHeap.pop() << " from maxHeap" << endl;
	cout << "Popped " << minHeap.pop() << " from minHeap" << endl;
	cout << "Popped " << maxHeap.pop() << " from maxHeap" << endl;
	cout << "Popped " << minHeap.pop() << " from minHeap" << endl;
	cout << "Popped " << maxHeap.pop() << " from maxHeap" << endl;
	cout << "Popped " << minHeap.pop() << " from minHeap" << endl;
	cout << "Popped " << maxHeap.pop() << " from maxHeap" << endl;
	try {
		minHeap.pop();
	} catch (NoSuchElementException &e) {
		cout << "Caught NoSuchElementException" << endl;
	}
	try {
		maxHeap.pop();
	} catch (NoSuchElementException &e) {
		cout << "Caught NoSuchElementException" << endl;
	}
	delete ltc;
	delete gtc;
	cout << endl;
}

void testTrie() {
	cout << "TESTING TRIE" << endl;
	Trie trie;
	trie.insert("he");
	trie.insert("hell");
	trie.insert("hear");
	trie.insert("heap");
	trie.insert("irk");
	trie.insert("ink");
	trie.insert("she");
	cout << "Contains hello: " << trie.contains("hello") << endl;
	cout << "Contains hell: " << trie.contains("hell") << endl;
	trie.insert("hello");
	cout << "Contains hello: " << trie.contains("hello") << endl;
	cout << "Words: " << endl;
	trie.printWords();
	trie.insert("irked");
	cout << "Words: " << endl;
	trie.printWords();
	cout << endl;
}