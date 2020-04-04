#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) {
	std::cout << "Con" << std::endl;
	return ;
}

Sample::~Sample(void) {
	std::cout << "Des" << std::endl;
	return ;
}