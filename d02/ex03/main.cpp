#include <iostream>
#include <bitset>
#include "fixed.hpp"

int main(void) {
	fixed::f i = fixed::int_to_fixed(1);
	fixed::f j = fixed::int_to_fixed(100);

	while (i < j) {
		++i;
	}

	return 0;
}