#include <iostream>
#include "Test.class.hpp"

Test::Test(void) {
	std::cout << "created" << std::flush;
}

Test::~Test(void) {
	std::cout << "deleted" << std::flush;
}