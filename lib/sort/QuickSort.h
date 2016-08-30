#pragma once
#include <vector>
#include "Sort.h"

template <class T>
class QuickSort : public Sort<T> {
	void sortHelper(std::vector<T> &vec) const;

public:
	std::vector<T> sort(const std::vector<T> &cvec) const;
};

#include "../../src/sort/QuickSort.cpp"