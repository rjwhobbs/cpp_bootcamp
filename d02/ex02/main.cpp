#include <iostream>
#include <bitset>
#include "Fixed.hpp"

int main(void) {
	Fixed d;
	Fixed c(8388607.234234f);
	Fixed e(234);

	d = c / e;
	std::cout.precision(20);
	std::cout << d << std::endl;
	d.showRawBits("D");
	return 0;
}