#include "../../lib/sort/BubbleSort.h"
using namespace std;

template <class T>
std::vector<T> BubbleSort<T>::sort(const vector<T> &cvec) const {
	std::vector<T> vec(cvec);
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 1; i < vec.size(); i++) {
			if (vec[i-1] > vec[i]) {
				T temp = vec[i-1];
				vec[i-1] = vec[i];
				vec[i] = temp;
				isSorted = false;
			}
		}
	}
	return vec;
}