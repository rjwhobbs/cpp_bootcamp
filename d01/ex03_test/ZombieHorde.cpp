#include <iostream>
// #include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int numZombies) : _numZombies(numZombies) {
	this->_zombies = new Zombie[numZombies];
	int i = 0;

	while (i < this->_numZombies) {
		this->_zombies[i].setType("heap");
		this->_zombies[i].setName(
			this->_zombieNameGen(
				this->_randIndex(10))
		);
		i++;
	}
}

ZombieHorde::~ZombieHorde(void) {
	delete [] this->_zombies;
	return ;
}

void ZombieHorde::announce() const {
	int i = 0;

	while (i < this->_numZombies) {
		this->_zombies[i++].announce();
	}
}

int ZombieHorde::_randIndex(int max) const {
	sranddev();
	int ranNum = rand() % max;

	if (ranNum < -1) {
		ranNum *= -1;
	}

	return ranNum;
}

std::string ZombieHorde::_zombieNameGen(int index) const {
	std::string names[10] = {
		"Steve", "Donald Trump", "Micheal J. Fox", "Lillian", "X",
		"Barbara", "Zoe", "The Dude", "Default Name", "The President of Cheese"};

	if (index >= 0 && index < 10){
		return names[index];
	} else {
		return names[0];
	}
}