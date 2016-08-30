#include "../../lib/sort/QuickSort.h"
using namespace std;

template <class T>
vector<T> QuickSort<T>::sort(const vector<T> &cvec) const {
	vector<T> vec(cvec);
	sortHelper(vec);
	return vec;
}

template <class T>
void QuickSort<T>::sortHelper(vector<T> &vec) const {
	if (vec.size() <= 1) return;
	vector<T> vec1;
	vector<T> vec2;
	T pivot = vec[0];
	for (unsigned int i = 1; i < vec.size(); i++) {
		if (vec[i] < pivot) {
			vec1.push_back(vec[i]);
		} else {
			vec2.push_back(vec[i]);
		}
	}
	sortHelper(vec1);
	sortHelper(vec2);
	vec.clear();
	for (unsigned int i = 0; i < vec1.size(); i++) {
		vec.push_back(vec1[i]);
	}
	vec.push_back(pivot);
	for (unsigned int i = 0; i < vec2.size(); i++) {
		vec.push_back(vec2[i]);
	}
}