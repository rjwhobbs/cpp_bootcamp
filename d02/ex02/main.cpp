#include <iostream>
#include <bitset>
#include "Fixed.hpp"

int main(void) {
	Fixed a(1.55f);
	Fixed b(1.55f);

	b.showRawBits("b");
	Fixed c = a * b;
	c.showRawBits("C");
	std::cout << std::fixed;
	std::cout << "C " << c << std::endl;
	return 0;
}