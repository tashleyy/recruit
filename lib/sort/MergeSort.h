#pragma once
#include <vector>
#include "Sort.h"

template <class T>
class MergeSort : public Sort<T> {
	void sortHelper(std::vector<T> &vec) const;
	void merge(const std::vector<T> &vec1, const std::vector<T> &vec2, std::vector<T> &vec) const;

public:
	std::vector<T> sort(const std::vector<T> &cvec) const;
};

#include "../../src/sort/MergeSort.cpp"