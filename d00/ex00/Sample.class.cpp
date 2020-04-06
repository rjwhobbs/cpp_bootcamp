#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) {
	std::cout << "Con" << std::endl;
	this->foo = 42;
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