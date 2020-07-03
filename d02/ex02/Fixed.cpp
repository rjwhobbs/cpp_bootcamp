#include <iostream>
#include <bitset>
#include "Fixed.hpp"

Fixed::Fixed (void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (Fixed const& src) {
	// Need to add protection against copying self
	// https://en.cppreference.com/w/cpp/language/operators
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

Fixed::Fixed (int64_t value) {
	this->_value = value;
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

void Fixed::setRawBits(int const value) {
	std::cout << "setRawBits member called" << std::endl;
	this->_value = value;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Assignation called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed& rhs) const {
	return Fixed(int64_t(this->_value + rhs.getRawBits()));
}

bool Fixed::operator<(Fixed const& rhs) {
	return this->_value < rhs.getRawBits() ? true : false; 
}

bool Fixed::operator>(Fixed const& rhs) {
	return this->_value > rhs.getRawBits() ? true : false; 
}

bool Fixed::operator<=(Fixed const& rhs) {
	return this->_value <= rhs.getRawBits() ? true : false; 
}

bool Fixed::operator>=(Fixed const& rhs) {
	return this->_value >= rhs.getRawBits() ? true : false; 
}

bool Fixed::operator==(Fixed const& rhs) {
	return this->_value == rhs.getRawBits() ? true : false; 
}

bool Fixed::operator!=(Fixed const& rhs) {
	return this->_value != rhs.getRawBits() ? true : false; 
}

int Fixed::toInt(void) const {
	// Maybe I should get the float val then cast to int?
	signed int pad = 0;

	if (this->_value < 0) {
		pad = 0xFF000000;
	} 

	unsigned int temp = ((this->_value & 0xFFFFFF00) >> Fixed::_scale) + pad;
	int out = temp;

	return out;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (float)(1 << Fixed::_scale);
}

void Fixed::showRawBits(std::string name) {
	std::bitset<32> out(this->getRawBits());
	std::cout<< "Bits for " << name << out << std::endl;
}

std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
	o << rhs.toFloat();
	return o;
}

int const Fixed::_scale = 8;