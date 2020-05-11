#include <iostream>
#include "Test.class.hpp"

Test::Test() {
	std::cout << "created " << std::endl;
	Test::_nbInst += 1;

	return ;
}

Test::Test(int x) {
	this->y = x;
	std::cout << "created " << x << std::endl;
	Test::_nbInst += 1;

	return ;
}

Test::~Test(void) {
	std::cout <<  Test::_nbInst <<" deleted" << std::endl;
	Test::_nbInst -= 1;

	return ;
}

int Test::getNbInst(void) {
	return Test::_nbInst;
}

// Only way to initialize a non member attribute
int Test::_nbInst = 0;