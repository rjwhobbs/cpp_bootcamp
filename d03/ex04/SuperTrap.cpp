#include <iostream>	
#include "SuperTrap.hpp"	
	
SuperTrap::SuperTrap (void) : 
	ClapTrap() {

	this->hit_points = FragTrap::hit_points;
	this->max_hit_points = FragTrap::max_hit_points;
	this->energy_points = NinjaTrap::energy_points;
	this->max_energy_points = NinjaTrap::max_energy_points;
	this->melee_attack_dmg = NinjaTrap::melee_attack_dmg;
	this->range_attack_dmg = FragTrap::range_attack_dmg;
	this->armor_dmg_reduction = FragTrap::armor_dmg_reduction;

	std::cout
		<< "SuperTrap default constructor called."
		<< std::endl;	
}	

SuperTrap::SuperTrap (std::string const name) :
	ClapTrap(name) {

	this->hit_points = FragTrap::hit_points;
	this->max_hit_points = FragTrap::max_hit_points;
	this->energy_points = NinjaTrap::energy_points;
	this->max_energy_points = NinjaTrap::max_energy_points;
	this->melee_attack_dmg = NinjaTrap::melee_attack_dmg;
	this->range_attack_dmg = FragTrap::range_attack_dmg;
	this->armor_dmg_reduction = FragTrap::armor_dmg_reduction;

	std::cout
		<< "SuperTrap by the name of "
		<< this->name
		<< " constructed."
		<< std::endl;	
}

SuperTrap::SuperTrap (SuperTrap const& src) {
	std::cout
		<< "SuperTrap copy constructor called"
		<< std::endl;

	*this = src;
}	
	
SuperTrap::~SuperTrap (void) {
	std::cout
		<< "SuperTrap destructor called."
		<< std::endl;		
}	
	
SuperTrap& SuperTrap::operator=(SuperTrap const& rhs) {	
	std::cout << "SuperTrap assignation called." << std::endl;	
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