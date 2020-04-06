#include <iostream>
#include "Sample.class.hpp"

int main(void) {
	Sample sample(7, 'y', 2.3);
	std::cout << sample.i << sample.c << sample.f << std::endl;
	sample.i = 42;
	std::cout << sample.i << std::endl;
	std::cout << sample.getj() << std::endl;
	// sample.bar();
	return 0;
}