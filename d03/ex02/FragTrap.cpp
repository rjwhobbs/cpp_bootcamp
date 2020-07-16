#include <iostream>	
#include <string>
#include <cstdlib>
#include "FragTrap.hpp"	
#include "ClapTrap.hpp"	
	
FragTrap::FragTrap (void) : 
	ClapTrap() {

	this->randAttacks[0] = &FragTrap::_acidPancakeAttack;
	this->randAttacks[1] = &FragTrap::_bakedInACakeAttack;
	this->randAttacks[2] = &FragTrap::_flamingFartAttack;
	this->randAttacks[3] = &FragTrap::_squirrelArmyAttack;
	this->randAttacks[4] = &FragTrap::_flyingPianoAttack;

	std::cout << "Just created a fragtrap with an empty name, why would you do such a thing?!" << std::endl;	
}

FragTrap::FragTrap (std::string const name) : 
	ClapTrap(name) {

	this->randAttacks[0] = &FragTrap::_acidPancakeAttack;
	this->randAttacks[1] = &FragTrap::_bakedInACakeAttack;
	this->randAttacks[2] = &FragTrap::_flamingFartAttack;
	this->randAttacks[3] = &FragTrap::_squirrelArmyAttack;
	this->randAttacks[4] = &FragTrap::_flyingPianoAttack;

	std::cout << "Created a fragtrap by the name of "
		<< this->name << ", good choice."
		<< std::endl;	
}	
	
FragTrap::FragTrap (FragTrap const& src) {

	this->randAttacks[0] = &FragTrap::_acidPancakeAttack;
	this->randAttacks[1] = &FragTrap::_bakedInACakeAttack;
	this->randAttacks[2] = &FragTrap::_flamingFartAttack;
	this->randAttacks[3] = &FragTrap::_squirrelArmyAttack;
	this->randAttacks[4] = &FragTrap::_flyingPianoAttack;

	std::cout << "Copied the fragtrap named "
		<< src.name
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
	std::cout << "FragTrap assignation called." << std::endl;	
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

void FragTrap::vaulthunter_dot_exe(std::string const& target) {
	int max_attacks = 5;
	if (this->energy_points >= 25) {
		(this->*randAttacks[FragTrap::_random_index(max_attacks)])(target);
		this->energy_points -= 25;
	}
	else {
		std::cout << "Can't perform attack, not enough energy points" << std::endl;
	}
}

int FragTrap::_random_index(int max) {
	sranddev();
	int ranNum = rand() % max;

	if (ranNum < 0) {
		ranNum *= -1;
	}

	return ranNum;
}

void FragTrap::_acidPancakeAttack(std::string const& target) {
	std::cout << this->name
		<< " forces "
		<< target 
		<< " to eat a pancake containing \"bad\" acid, causing "
		<< " 50 damage points."
		<< std::endl;
}

void FragTrap::_flamingFartAttack(std::string const& target) {
	std::cout << this->name
		<< " attacks "
		<< target 
		<< " with a flaming mega fart, causing "
		<< "50 damage points."
		<< std::endl;
}

void FragTrap::_squirrelArmyAttack(std::string const& target) {
	std::cout << this->name
		<< " attacks "
		<< target 
		<< " with an army of squirrels, causing "
		<< "50 damage points."
		<< std::endl;
}

void FragTrap::_flyingPianoAttack(std::string const& target) {
	std::cout << this->name
		<< " attacks "
		<< target 
		<< " with a fly piano, causing "
		<< "50 damage points and severe hearing loss."
		<< std::endl;
}

void FragTrap::_bakedInACakeAttack(std::string const& target) {
	std::cout << this->name
		<< " bakes "
		<< target 
		<< " into a cake, causing "
		<< "50 damage points."
		<< std::endl;
}