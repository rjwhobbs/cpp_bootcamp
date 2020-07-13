#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cstdlib>
#include "FragTrap.hpp"

int random_index(int max) {
	sranddev();
	int ranNum = rand() % max;

	if (ranNum < -1) {
		ranNum *= -1;
	}

	return ranNum;
}

int main(void) {
	FragTrap a("Steve");


	int i = 0;
	while (i++ < 20) {
		a.vaulthunter_dot_exe("Joe");
	}

	return 0;	
}