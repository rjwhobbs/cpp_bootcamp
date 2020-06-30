#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed (void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed (void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(const int value) {
	std::cout << "setRawBits member called" << std::endl;
	this->_value = value;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Assignation called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

int const Fixed::_scale = 8;