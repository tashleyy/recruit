#include <algorithm>
#include <iostream>
#include <vector>
#include "../lib/sort/BubbleSort.h"
#include "../lib/sort/SelectionSort.h"
using namespace std;

void print(const vector<int> &vec);

int main (int argc, char **argv) {
	vector<int> vec;
	vector<Sort<int>*> sorts;
	sorts.push_back(new BubbleSort<int>);
	sorts.push_back(new SelectionSort<int>);
	srand(time(0));
	for (unsigned int i = 0; i < 25; i++) {
		vec.push_back(rand() % 100);
	}
	print(vec);
	for (unsigned int i = 0; i < sorts.size(); i++) {
		print(sorts[i]->sort(vec));
	}
	return 0;
}

void print(const vector<int> &vec) {
	for_each(vec.begin(), vec.end(), [](const int &n) {
		cout << n << " ";
	});
	cout << endl;
}