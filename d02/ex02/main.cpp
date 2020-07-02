#include <iostream>
#include "Fixed.hpp"

int main(void) {
	Fixed a;

	a.setRawBits(1);

	std::cout << a << std::endl;
	return 0;
}