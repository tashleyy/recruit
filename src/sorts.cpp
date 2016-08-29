#include <algorithm>
#include <iostream>
#include <vector>
#include "../lib/sort/BubbleSort.h"
using namespace std;

void print(const vector<int> &vec);

int main (int argc, char **argv) {
	vector<int> vec;
	BubbleSort<int> bubbleSort;
	srand(time(0));
	for (unsigned int i = 0; i < 15; i++) {
		vec.push_back(rand() % 100);
	}
	print(vec);
	print(bubbleSort.sort(vec));
	return 0;
}

void print(const vector<int> &vec) {
	for_each(vec.begin(), vec.end(), [](const int &n) {
		cout << n << " ";
	});
	cout << endl;
}