#include <iostream>	
#include "Sorcerer.hpp"
#include "Victim.hpp"	
	
Victim::Victim (void) :
	_name("") {

	std::cout
		<< "Default Victim constructor."
		<< std::endl;	
}

Victim::Victim (std::string const name) : 
	_name(name) {
	
	std::cout
		<< "(Victim con) Some random victim called " 
		<< this->_name 
		<< " just popped !"
		<< std::endl;
}
	
Victim::Victim (Victim const& src) {	
	*this = src;
}	
	
Victim& Victim::operator=(Victim const& rhs) {	
	if (this != &rhs) {
		this->_name = rhs.getName();
	}	
	return *this;	
}

Victim::~Victim (void) {
	std::cout
		<< "Victim " 
		<< this->_name 
		<< " just died for no apparent reason !"
		<< std::endl;	
}	

std::string Victim::getName(void) const {
	return this->_name;
}

void Victim::getPolymorphed(void) const {
	std::cout
		<< this->_name
		<< " has been turned into a cute little sheep !"
		<< std::endl;
}

std::ostream& operator<<(std::ostream& o, Victim const& rhs) {
	o << "I'm " 
		<< rhs.getName()
		<< " and I like otters !"
		<< std::endl;

	return o;
}