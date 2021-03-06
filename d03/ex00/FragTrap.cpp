#include <iostream>	
#include <string>
#include <cstdlib>
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

	this->randAttacks[0] = &FragTrap::_acidPancakeAttack;
	this->randAttacks[1] = &FragTrap::_bakedInACakeAttack;
	this->randAttacks[2] = &FragTrap::_flamingFartAttack;
	this->randAttacks[3] = &FragTrap::_squirrelArmyAttack;
	this->randAttacks[4] = &FragTrap::_flyingPianoAttack;

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
		if (amount <= this->hit_points) {
			this->hit_points -= amount;
		}
		else {
			this->hit_points = 0;
		}
	}
	std::cout << this->name
		<< " was attacked with "
		<< amount
		<< " damage points and has "
		<< this->hit_points
		<< " HP left."
		<< std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
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

void FragTrap::vaulthunter_dot_exe(std::string const& target) {
	int max_attacks = 5;
	if (this->energy_points >= 25) {
		(this->*randAttacks[FragTrap::_random_index(max_attacks)])(target);
		this->energy_points -= 25;
	}
	else {
		std::cout << "Can't perform attack, not enough energy points" << std::endl;
	}
	std::cout << "Here" << std::endl;
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