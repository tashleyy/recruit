#pragma once
#include <vector>
#include "Sort.h"

template <class T>
class SelectionSort : public Sort<T> {
public:
	std::vector<T> sort(const std::vector<T> &cvec) const;
};

#include "../../src/sort/SelectionSort.cpp"