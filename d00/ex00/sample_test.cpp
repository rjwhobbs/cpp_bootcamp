#include <iostream>
#include "Sample.class.hpp"

int main(void) {
	Sample sample;
	// sample.foo = 42;
	std::cout << sample.foo << std::endl;
	sample.bar();
	return 0;
}