#pragma once
#include "Sort.h"

template <class T>
class BubbleSort : public Sort<T> {
public:
	std::vector<T> sort(const std::vector<T> &cvec) const;
};

#include "../../src/sort/BubbleSort.cpp"