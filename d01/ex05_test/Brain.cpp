#include <string>
#include <sstream>
#include "Brain.hpp"

Brain::Brain(void) {
	this->_humanAddress = "potato";
	return ;
}

Brain::~Brain(void) {
	return ;
}

std::string Brain::identify(void) const {
	std::stringstream addressStream;
	std::string address;

	addressStream << this;
	address = addressStream.str();

	return address;
}
