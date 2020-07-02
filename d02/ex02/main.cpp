#include <iostream>
#include "Fixed.hpp"

int main(void) {
	Fixed a(10);
	Fixed b(1);

	std::cout << (b < a) << std::endl;
	return 0;
}