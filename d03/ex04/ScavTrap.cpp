#include <iostream>	
#include "ScavTrap.hpp"	
	
ScavTrap::ScavTrap (void) :
	ClapTrap() {
	
	this->energy_points = 50;
	this->melee_attack_dmg = 20;
	this->range_attack_dmg = 15;
	this->armor_dmg_reduction = 3;

	this->randomChallenges[0] = &ScavTrap::_burpingChallenge;	
	this->randomChallenges[1] = &ScavTrap::_codingChallenge;	
	this->randomChallenges[2] = &ScavTrap::_eatMarshmelloChallenge;	
	this->randomChallenges[3] = &ScavTrap::_gameOfSkateChallenge;	
	this->randomChallenges[4] = &ScavTrap::_playScrabbleChallenge;	

	std::cout 
		<< "Just created a scavtrap with an empty name, why would you do such a thing?!" << std::endl;	
}	

ScavTrap::ScavTrap(std::string const name) : 
	ClapTrap(name) {

	this->energy_points = 50;
	this->melee_attack_dmg = 20;
	this->range_attack_dmg = 15;
	this->armor_dmg_reduction = 3;

	this->randomChallenges[0] = &ScavTrap::_burpingChallenge;	
	this->randomChallenges[1] = &ScavTrap::_codingChallenge;	
	this->randomChallenges[2] = &ScavTrap::_eatMarshmelloChallenge;	
	this->randomChallenges[3] = &ScavTrap::_gameOfSkateChallenge;	
	this->randomChallenges[4] = &ScavTrap::_playScrabbleChallenge;	

	std::cout 
		<< "Created a scavtrap by the name of "
		<< this->name
		<< std::endl;		
}
	
ScavTrap::ScavTrap (ScavTrap const& src) {

	std::cout 
		<< "Copied a scavtrap named "
		<< src.name
		<< std::endl;

	this->randomChallenges[0] = &ScavTrap::_burpingChallenge;	
	this->randomChallenges[1] = &ScavTrap::_codingChallenge;	
	this->randomChallenges[2] = &ScavTrap::_eatMarshmelloChallenge;	
	this->randomChallenges[3] = &ScavTrap::_gameOfSkateChallenge;	
	this->randomChallenges[4] = &ScavTrap::_playScrabbleChallenge;

	*this = src;	
}	
	
ScavTrap::~ScavTrap (void) {
	std::cout 
		<< "A scavtrap by the name of " 
		<< this->name 
		<< " just got destroyed, gonna miss the little guy."
		<< std::endl;		
}	
	
ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {	
	std::cout << "Scavtrap assignation called." << std::endl;	
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

void ScavTrap::challengeNewcomer(std::string const& target) {
	int max_attacks = 5;

	(this->*randomChallenges[ScavTrap::_random_index(max_attacks)])(target);
}

void ScavTrap::_playScrabbleChallenge(std::string const& target) {
	std::cout
		<< this->name
		<< " challenges "
		<< target 
		<< " to play a game of scrabble."
		<< std::endl;
}

void ScavTrap::_eatMarshmelloChallenge(std::string const& target) {
	std::cout
		<< this->name
		<< " challenges "
		<< target 
		<< " to a marshmello eating competition."
		<< std::endl;
}

void ScavTrap::_burpingChallenge(std::string const& target) {
	std::cout
		<< this->name
		<< " challenges "
		<< target 
		<< " to a burping competition."
		<< std::endl;
}

void  ScavTrap::_gameOfSkateChallenge(std::string const& target) {
	std::cout
		<< this->name
		<< " challenges "
		<< target 
		<< " to a game of skate."
		<< std::endl;
}

void ScavTrap::_codingChallenge(std::string const& target) {
	std::cout
		<< this->name
		<< " challenges "
		<< target 
		<< " to a c++ coding dual."
		<< std::endl;
}

int ScavTrap::_random_index(int max) {
	sranddev();
	int ranNum = rand() % max;

	if (ranNum < 0) {
		ranNum *= -1;
	}

	return ranNum;
}