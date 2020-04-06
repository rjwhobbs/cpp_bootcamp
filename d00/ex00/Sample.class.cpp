#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(int i, char c, float f) : i(i), c(c), f(f) {
	std::cout << "Con" << std::endl;
	
	// this->foo = 42; // this is a pointer to the class instance
	this->bar();
	return ;
}

Sample::~Sample(void) {
	std::cout << "Des" << std::endl;
	return ;
}

void Sample::bar(void) {
	std::cout << "I am bar func" << std::endl;
	return ;
}