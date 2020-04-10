#include <iostream>
#include "SamThree.class.hpp"

int	SamThree::_foo = 0;

SamThree::SamThree() {
	std::cout << "Con" << std::endl;
	this->_foo += 1;
	std::cout << this->_foo << std::endl;

	return ;
}

SamThree::~SamThree() {
	std::cout << "Des" << std::endl;
	this->_foo -= 1;
	std::cout << this->_foo << std::endl;

	return ;
}

int	SamThree::getFoo(void) {
	return SamThree::_foo;
}