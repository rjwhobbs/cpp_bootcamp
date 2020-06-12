#include <iostream>
#include <string>
#include <sstream>
#include "Human.hpp"
#include "Brain.hpp"

int main(void) {
	Human bob;
	
	// std::cout << bob.identify() << std::endl;
	// std::cout << bob.getBrain().identify() << std::endl;

	int x = bob.getX();
	int y = bob.getX();
	std::cout << &x << std::endl;
	std::cout << &x << std::endl;
	std::cout << &y << std::endl;

	return 0;
}