#include <iostream>	
#include <string>
#include "FragTrap.hpp"	
	
FragTrap::FragTrap (void) : 
	name(""),
	level(1),
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	melee_attack_dmg(30),
	range_attack_dmg(20),
	armor_dmg_reduction(5) {

	std::cout << "Just created a fragtrap with an empty name, why would you do such a thing?!" << std::endl;	
}

FragTrap::FragTrap (std::string const name) :
	name(name),
	level(1),
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	melee_attack_dmg(30),
	range_attack_dmg(20),
	armor_dmg_reduction(5) {

	std::cout << "Created a fragtrap by the name of "
		<< this->name << ", good choice."
		<< std::endl;	
}	
	
FragTrap::FragTrap (FragTrap const& src) {	
	std::cout << "Copied the fragtrap named "
		<< this->name
		<< std::endl;
	*this = src;
}	
	
FragTrap::~FragTrap (void) {
	std::cout << "A fragtrap by the name of " 
		<< this->name 
		<< " just got destroyed, he was annoying anyway."
		<< std::endl;	
}	
	
FragTrap& FragTrap::operator=(FragTrap const& rhs) {
	std::cout << "Assignation called." << std::endl;	
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

void FragTrap::rangedAtack(std::string const& target) {
	std::cout << this->name
		<< " attacks "
		<< target 
		<< " with a ranged attack, causing "
		<< this->range_attack_dmg
		<< " damage points."
		<< std::endl;
}

void FragTrap::meleeAttack(std::string const& target) {
	std::cout << this->name
		<< " attacks "
		<< target 
		<< " with a melee attack, causing "
		<< this->melee_attack_dmg
		<< " damage points."
		<< std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (amount > this->armor_dmg_reduction) {
		amount -= this->armor_dmg_reduction;
		if (amount < this->hit_points) {
			this->hit_points -= amount;
		}
		else {
			this->hit_points = 0;
		}
	}
	std::cout << this->name
		<< " was attacke with "
		<< amount
		<< " damage points and has "
		<< this->hit_points
		<< " HP left."
		<< std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (amount + this->energy_points < this->max_energy_points) {
		this->energy_points += amount;
	}
	else {
		this->energy_points = this->max_energy_points;
	}
	std::cout << this->name
		<< " was repaired with "
		<< amount
		<< " energy points and has a total of "
		<< this->energy_points
		<< "."
		<< std::endl;
}