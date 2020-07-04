#include <iostream>
#include <bitset>
#include "../ex02/Fixed.hpp"

int main(void) {
	Fixed i(1);
	Fixed j(1000);

	while (i < j) {
		++i;
	}

	return 0;
}