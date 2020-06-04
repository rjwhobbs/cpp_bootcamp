#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name) 
	: _type(type), _name(name) {
	std::cout << "A " << this->_type << " zombie named "
	<< this->_name << " has spawned :o+<" << std::endl;

	return ; 														
}

Zombie::Zombie(void) {
	return ;
}

Zombie::~Zombie(void) {
	std::cout << "A " << this->_type << " zombie named "
	<< this->_name << " has had it's brains blown out." << std::endl;
}

void Zombie::announce(void) const {
	std::cout << this->_name << ", a " << this->_type 
	<< " zombie has the following to say, \"BRrrrrAAAIiiIIiNnNnnS\"" << std::endl;
}

void Zombie::setType(std::string type) {
	this->_type = type;
}
void Zombie::setName(std::string name) {
	this->_name = name;
}