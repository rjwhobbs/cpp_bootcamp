#include <iostream>
#include <bitset>
#include "fixed.hpp"

int main(void) {
	fixed::f a = fixed::int_to_fixed(10);
	fixed::f b = fixed::float_to_fixed(9.9f);

	std::cout << fixed::fixed_to_float(b) << std::endl;
	std::cout << fixed::fixed_to_float(a) << std::endl;
	return 0;
}