#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"

int main(void) {
	Zombie* zombies = new Zombie[10];

	for (int i = 0; i < 10; i++) {
		zombies[i].announce();
	}

	return 0;
}