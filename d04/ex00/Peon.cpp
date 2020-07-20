#include <iostream>	
#include "Peon.hpp"	
#include "Victim.hpp"
	
Peon::Peon (void) :
	Victim() {

	std::cout
		<< "Default Peon constructor."
		<< std::endl;	
}	

Peon::Peon(std::string const name) : 
	Victim(name) {
	
	std::cout
		<< "Param Peon constructor"
		<< std::endl;
}

Peon::Peon (Peon const& src) {
	*this = src;	
}	
	
// Peon::~Peon (void) {	
// }	
	
Peon& Peon::operator=(Peon const& rhs) {	
	if (this != &rhs) {
		this->_name = rhs.getName();
	}	
	return *this;	
}