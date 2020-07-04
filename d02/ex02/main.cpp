#include <iostream>
#include <bitset>
#include "Fixed.hpp"

int main(void) {
	Fixed d(1);
	Fixed a(2);
	// Fixed c(8388607.234234f);
	// Fixed e(234);

	std::cout.precision(20);

	int c = 0;
	while (d < a) {
		c++;
		d++;
		std::cout << d << std::endl;
	}

	std::cout << c << std::endl;
	// std::cout << d << std::endl;
	d.showRawBits("D");
	return 0;
}