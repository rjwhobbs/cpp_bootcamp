#include <iostream>
#include <bitset>
#include "Fixed.hpp"

int main(void) {
	Fixed a(1);
	Fixed b(1.1f);

	b.showRawBits("b");
	Fixed c = a + b;
	c.showRawBits("C");
	std::cout << "C " << c << std::endl;
	return 0;
}