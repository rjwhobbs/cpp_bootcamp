#include <iostream>
#include "Simple.class.hpp"

Simple::Simple(void) {
	std::cout << "Con" << std::endl;

	return ;
}

Simple::~Simple(void) {
	std::cout << "Des" << std::endl;
	return ;
}

void Simple::bar(void) const {
	std::cout << "I am bar func" << std::endl;
	// this->i = 93; Can't do this as bar is const and can't modify 'this'

	return ;
}