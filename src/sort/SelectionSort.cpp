#include "../../lib/sort/SelectionSort.h"
using namespace std;

template <class T>
vector<T> SelectionSort<T>::sort(const vector<T> &cvec) const {
	vector<T> vec(cvec);
	if (vec.size() <= 1) return vec;
	int start = 0;
	while (start < vec.size()) {
		int min = start;
		for (int i = start+1; i < vec.size(); i++) {
			if (vec[i] < vec[min]) {
				min = i;
			}
		}
		T temp = vec[start];
		vec[start] = vec[min];
		vec[min] = temp;
		start++;
	}
	return vec;
}