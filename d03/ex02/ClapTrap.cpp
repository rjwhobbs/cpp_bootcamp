#include <iostream>	
#include "ClapTrap.hpp"	
	
ClapTrap::ClapTrap (void) :
	name(""),
	level(1),
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	melee_attack_dmg(30),
	range_attack_dmg(20),
	armor_dmg_reduction(5) {

	std::cout
		<< "ClapTrap default constructor called"
		<< std::endl;
}	

ClapTrap::ClapTrap (std::string const name) : 
	name(name),
	level(1),
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	melee_attack_dmg(30),
	range_attack_dmg(20),
	armor_dmg_reduction(5) {

	std::cout
		<< "ClapTrap \"name\" constructor called"
		<< std::endl;	
}

ClapTrap::ClapTrap (ClapTrap const& src) {
	std::cout
		<< "ClapTrap copy constructor called"
		<< std::endl;	
}	
	
ClapTrap::~ClapTrap (void) {	
	std::cout
		<< "ClapTrap destructor called"
		<< std::endl;	
}	
	
ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {	
	std::cout << "ClapTrap assignation called." << std::endl;	
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