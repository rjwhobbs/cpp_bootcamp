#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
	ZombieEvent betterThanAverageZombieEvent;
	betterThanAverageZombieEvent.setZombieType("better than average");
	Zombie* joe = betterThanAverageZombieEvent.newZombie("Joe");
	joe->announce();
	delete joe;
	return 0;
}