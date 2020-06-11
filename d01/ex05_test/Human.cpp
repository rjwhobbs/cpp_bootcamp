#include <iostream>
#include <string>
#include <sstream>
#include "Brain.hpp"
#include "Human.hpp"

Human::Human() {
	return ;
}

Human::~Human(void) {
	return ;
}

std::string Human::identify(void) const {
	// std::cout << "H i" << this << std::endl;
	return this->brain.identify();
}

Brain& Human::getBrain(void) {
	// std::cout << "gb" << this->brain.identify() << std::endl;
	return this->brain;
}