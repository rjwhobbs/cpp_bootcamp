#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) 
: _name(name), _weapon(weapon) {
	return;
}

HumanA::~HumanA(void) {
	return;
}

void HumanA::attack() const {
	// std::cout <<
}

