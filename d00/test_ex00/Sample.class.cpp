#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(int x, char y, float z) : i(x), c(y), f(z) {
	std::cout << "Con" << std::endl;

	// this->foo = 42; // this is a pointer to the class instance
	this->bar();
	this->_j = 13;
	std::cout << this->_j << std::endl;
	this->_pbar();
	return ;
}

Sample::~Sample(void) {
	std::cout << "Des" << std::endl;
	return ;
}

void Sample::bar(void) const {
	std::cout << "I am bar func" << std::endl;
	// this->i = 93; Can't do this as bar is const and can't modify 'this'

	return ;
}

void Sample::_pbar(void) const {
	std::cout << "I am _pbar func" << std::endl;
	// this->i = 93; Can't do this as bar is const and can't modify 'this'

	return ;
}

int Sample::getj(void) const {
	return this->_j;
}