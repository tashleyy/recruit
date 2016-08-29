#include "../../lib/sort/MergeSort.h"
using namespace std;

template <class T>
vector<T> MergeSort<T>::sort(const vector<T> &cvec) const {
	vector<T> vec(cvec);
	sortHelper(vec);
	return vec;
}

template <class T>
void MergeSort<T>::sortHelper(vector<T> &vec) const {
	if (vec.size() <= 1) return;
	vector<T> vec1(vec.begin(), vec.begin()+vec.size()/2);
	vector<T> vec2(vec.begin()+vec.size()/2, vec.end());
	sortHelper(vec1);
	sortHelper(vec2);
	merge(vec1, vec2, vec);
}

template <class T>
void MergeSort<T>::merge(const vector<T> &vec1, const vector<T> &vec2, vector<T> &vec) const {
	int i = 0, j = 0, k = 0;
	while (i < vec1.size() && j < vec2.size()) {
		if (vec1[i] < vec2[j]) {
			vec[k] = vec1[i];
			i++;
			k++;
		} else {
			vec[k] = vec2[j];
			j++;
			k++;
		}
	}
	while (i < vec1.size()) {
		vec[k] = vec1[i];
		i++;
		k++;
	}
	while (j < vec2.size()) {
		vec[k] = vec2[j];
		j++;
		k++;
	}
}