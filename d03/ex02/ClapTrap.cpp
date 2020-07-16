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

	*this = src;	
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

void ClapTrap::rangedAtack(std::string const& target) {
	std::cout << this->name
		<< " attacks "
		<< target 
		<< " with a ranged attack, causing "
		<< this->range_attack_dmg
		<< " damage points."
		<< std::endl;
}

void ClapTrap::meleeAttack(std::string const& target) {
	std::cout << this->name
		<< " attacks "
		<< target 
		<< " with a melee attack, causing "
		<< this->melee_attack_dmg
		<< " damage points."
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->armor_dmg_reduction) {
		amount -= this->armor_dmg_reduction;
		if (amount <= this->hit_points) {
			this->hit_points -= amount;
		}
		else {
			this->hit_points = 0;
		}
	}
	std::cout << this->name
		<< " has taken "
		<< amount
		<< " damage points and has "
		<< this->hit_points
		<< " HP left."
		<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (amount + this->hit_points <= this->max_hit_points) {
		this->hit_points += amount;
	}
	else {
		this->hit_points = this->max_hit_points;
	}
	std::cout << this->name
		<< " was repaired with "
		<< amount
		<< " hit points and has a total of "
		<< this->hit_points
		<< " hit points."
		<< std::endl;
}