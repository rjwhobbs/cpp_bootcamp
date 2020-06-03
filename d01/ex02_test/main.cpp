#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int random_index(int max) {
	sranddev();
	int ranNum = rand() % max;

	return ranNum;
}

std::string zombieNameGen(int index) {
	std::string names[10] = {
		"Steve", "Donald Trump", "Micheal J. Fox", "Lillian", "X",
		"Barbara", "Zoe", "The Dude", "Default Name", "The President of Cheese"};

	return names[index];
}

void randomChump(void) {
	Zombie randomZombie("stack Zombie", zombieNameGen(random_index(10)));
	randomZombie.announce();
}

int main(void) {
	ZombieEvent betterThanAverageZombieEvent;
	betterThanAverageZombieEvent.setZombieType("better than average");
	Zombie* joe = betterThanAverageZombieEvent.newZombie("Joe");
	Zombie* steve = betterThanAverageZombieEvent.newZombie("Steve");
	joe->announce();
	steve->announce();
	randomChump();
	delete joe;
	delete steve;
	return 0;
}