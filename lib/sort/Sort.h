#pragma once
#include <vector>

template <class T>
class Sort {
public:
	virtual std::vector<T> sort(const std::vector<T> &vec) const = 0;
};