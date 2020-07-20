#include <iostream>	
#include <ostream>
#include <string>
#include "Sorcerer.hpp"	
	
Sorcerer::Sorcerer (void) :
	_name(""),
	_title("") {	
	std::cout
		<< "Default sorcerer constructor called."
		<< std::endl;
}	

Sorcerer::Sorcerer(std::string const name, std::string const title) :
	_name(name),
	_title(title) {

	std::cout
		<< this->_name
		<< ", "
		<< this->_title
		<< ", is born !"
		<< std::endl;
}
	
Sorcerer::Sorcerer (Sorcerer const& src) {
	*this = src;	
}	
	
Sorcerer::~Sorcerer (void) {
	std::cout
		<< this->_name
		<< ", "
		<< this->_title
		<< ", "
		<< "is dead. Consequences will never be the same !"
		<< std::endl;	
}	
	
Sorcerer& Sorcerer::operator=(Sorcerer const& rhs) {	
	if (this != &rhs)	 {
		this->_name = rhs.getName();
		this->_title = rhs.getTitle();
	}
	return *this;	
}

std::string Sorcerer::getName(void) const {
	return this->_name;
}

std::string Sorcerer::getTitle(void) const {
	return this->_title;
}

std::ostream& operator<<(std::ostream& o, Sorcerer const& rhs){
	o << "I am " 
		<< rhs.getName()
		<< ", "
		<< rhs.getTitle()
		<< ", and I like ponies !"
		<< std::endl;
	return o;
}