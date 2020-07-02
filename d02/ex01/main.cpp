#include <iostream>
#include "Fixed.hpp"

int main(void) {
	Fixed a(42.42f);
	Fixed b(-42.42f);
	Fixed c(42.0f);
	Fixed d(-42.0f);

	std::cout << "a \n" << a.toInt() << std::endl;
	std::cout << "b \n" << b.toInt() << std::endl;
	std::cout << "d \n" << d.toInt() << std::endl;
	std::cout << "c \n" << c.toInt() << std::endl;

	std::cout << "a \n" << a << std::endl;
	std::cout << "b \n" << b << std::endl;
	std::cout << "d \n" << d << std::endl;
	std::cout << "c \n" << c << std::endl;

	return 0;
}