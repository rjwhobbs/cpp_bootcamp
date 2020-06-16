#include <cstddef>
#include <iostream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
: _name(name) {
	this->_weapon = nullptr;

	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack() const {
	std::string weapon;

	if (this->_weapon) {
		weapon = this->_weapon->getType();
	}

	std::cout 
		<< this->_name 
		<< " attacks with his " 
		<< weapon 
		<< std::endl;
}