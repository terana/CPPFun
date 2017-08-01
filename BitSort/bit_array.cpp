#include "bit_array.h"
#include <stdexcept>
#include <iostream>

#define BITMASK 0x1F
#define SHIFT 5

bit_array::bit_array(int size) : size_(size) {
	arr_ = new int[(size>>SHIFT) + 1];
};

void bit_array::set(int i) {
	if (i >= size_)
		throw std::invalid_argument("out of limits");
	arr_[i>>SHIFT] |= 1 << (i & BITMASK);
}

void bit_array::clr(int i) {
	if (i >= size_)
		throw std::invalid_argument("out of limits");
	arr_[i>>SHIFT] &= ~(1 << (i & BITMASK));
}

int bit_array::test(int i) {
	if (i >= size_)
		throw std::invalid_argument("out of limits");
	return arr_[i>>SHIFT] & (1 << (i & BITMASK)) ? 1 : 0;
}

void bit_array::print() {
	for (int i = 0; i < size_; i++) {
		std::cout<< test(i);
	}
	std::cout<<"\n";
}
