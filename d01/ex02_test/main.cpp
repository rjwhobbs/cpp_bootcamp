#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int random_index(int max) {
	sranddev();
	int ranNum = rand() % max;

	if (ranNum < -1) {
		ranNum *= -1;
	}

	return ranNum;
}

std::string zombieNameGen(int index) {
	std::string names[10] = {
		"Steve", "Donald Trump", "Micheal J. Fox", "Lillian", "X",
		"Barbara", "Zoe", "The Dude", "Default Name", "The President of Cheese"};

	if (index >= 0 && index < 10){
		return names[index];
	} else {
		return names[0];
	}
}

void randomChump(void) {
	Zombie randomZombie("stack", zombieNameGen(random_index(10)));
	randomZombie.announce();
}

int main(void) {
	ZombieEvent heapZombie;

	heapZombie.setZombieType("heap");
	Zombie* joe = heapZombie.newZombie("Joe");
	Zombie* steve = heapZombie.newZombie("Steve");
	Zombie* randomZombie = heapZombie.newZombie(zombieNameGen(random_index(10)));

	if (joe && steve && randomZombie) {
		joe->announce();
		steve->announce();
		randomZombie->announce();
	} else {
		std::cerr << "Looks like we had a problem allocating one or more of your zombies"
		<< std::endl;
	}

	randomChump();
	randomChump();

	if (joe) {
		delete joe;
	}
	if (steve) {
		delete steve;
	}
	if (randomZombie) {
		delete randomZombie;
	}

	return 0;
}