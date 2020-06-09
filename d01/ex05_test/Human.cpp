#include <iostream>
#include <string>
#include <sstream>
#include "Brain.hpp"
#include "Human.hpp"

Human::Human(void) {
	return ;
}

Human::~Human(void) {
	return ;
}

std::string Human::identify(void) const {
	return this->brain->identify();
}

Brain* Human::getBrain(void) const {
	return this->brain;
}