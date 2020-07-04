#include <iostream>
#include <bitset>
#include "Fixed.hpp"

int main(void) {
	Fixed d(2);
	Fixed a(1);
	Fixed const x(2);
	Fixed const z(1);
	Fixed& c = Fixed::min(a, d);
	Fixed const& f = Fixed::min(x, z);

	std::cout << c << std::endl;
	std::cout << "Const min" << f << std::endl;
	c.setRawBits(123123);
	std::cout << a.getRawBits() << std::endl;
	return 0;
}