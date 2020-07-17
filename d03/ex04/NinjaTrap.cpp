#include <iostream>	
#include "NinjaTrap.hpp"	
#include "ClapTrap.hpp"
	
NinjaTrap::NinjaTrap (void) : ClapTrap() {
	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->melee_attack_dmg = 60;
	this->range_attack_dmg = 5;
	this->armor_dmg_reduction = 0;

	std::cout 
		<< "NinjaTrap defualt constructor called"
		<< std::endl;
}

NinjaTrap::NinjaTrap (std::string const name) : 
	ClapTrap(name) {
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->melee_attack_dmg = 60;
	this->range_attack_dmg = 5;
	this->armor_dmg_reduction = 0;

	std::cout
		<< "NinjaTrap by the name of " 
		<< this->name 
		<< " has been created."
		<< std::endl;
}
	
NinjaTrap::NinjaTrap (NinjaTrap const& src) {	
	std::cout
		<< "NinjaTrap copy constructor called"
		<< std::endl;

	*this = src;	
}	
	
NinjaTrap::~NinjaTrap (void) {	
	std::cout << "A NinjaTrap by the name of " 
		<< this->name 
		<< " just got destroyed, or is he jsut hidding?"
		<< std::endl;	
}	
	
NinjaTrap& NinjaTrap::operator=(NinjaTrap const& rhs) {	
	std::cout << "NinjaTrap assignation called." << std::endl;	
	if (this != &rhs) {
		this->name = rhs.name;
		this->level = rhs.level;
		this->hit_points = rhs.hit_points;
		this->max_hit_points = rhs.max_hit_points;
		this->energy_points = rhs.energy_points;
		this->max_energy_points = rhs.max_energy_points;
		this->melee_attack_dmg = rhs.melee_attack_dmg;
		this->range_attack_dmg = rhs.range_attack_dmg;
		this->armor_dmg_reduction = rhs.armor_dmg_reduction;
	}	
	return *this;	
}

void NinjaTrap::ninjaShoebox(NinjaTrap const& target) {
	if (this != &target) {
		std::cout
			<< "A NinjaTrap named "
			<< this->name
			<< " has hidden himself in a shoebox and launches a surprise attack on another NinjaTrap called "
			<< target.name
			<< " ."
			<< std::endl;
	} else {
		std::cout
			<< "Potato, you can't shoebox attack yourself"
			<< std::endl;
	}
}

void NinjaTrap::ninjaShoebox(FragTrap const& target) {
	std::cout
		<< "A NinjaTrap named "
		<< this->name
		<< " has hidden himself in a shoebox and launches a surprise attack on a FragTrap called "
		<< target.name
		<< " ."
		<< std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap const& target) {
	std::cout
		<< "A NinjaTrap named "
		<< this->name
		<< " has hidden himself in a shoebox and launches a surprise attack on a ScavTrap called "
		<< target.name
		<< " ."
		<< std::endl;
}