#include <iostream>
#include "Fixed.hpp"
// Delete me
#include <bitset>

Fixed::Fixed (void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed (int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << Fixed::_scale;
}

Fixed::Fixed (float const value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = (value * (float)(1 << Fixed::_scale));
}

Fixed::~Fixed (void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member called" << std::endl;
	return this->_value;
}

int Fixed::getScale(void) const {
	return Fixed::_scale;
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

int Fixed::toInt(void) const {
	signed int pad = 0;

	if (this->_value < 0) {
		pad = 0xFF000000;
	} 

	unsigned int temp = ((this->_value & 0xFFFFFF00) >> Fixed::_scale) + pad;
	int ret = temp;

	std::bitset<32> A(this->_value);
  std::cout << "A - " << A << std::endl;
	std::bitset<32> B(ret);
  std::cout << "B - " << B << std::endl;
	return ret;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (float)(1 << Fixed::_scale);
}

std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
	o << rhs.toFloat();
	return o;
}

int const Fixed::_scale = 8;