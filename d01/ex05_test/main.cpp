#include <iostream>
#include <string>
#include <sstream>
#include "Human.hpp"
#include "Brain.hpp"

int main(void) {
	Human human;
	Brain brain;
	std::cout << human.identify() << std::endl;
	std::cout << human.getBrain().identify() << std::endl;
}