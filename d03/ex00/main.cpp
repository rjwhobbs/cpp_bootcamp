#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cstdlib>
#include "FragTrap.hpp"

int main(void) {
	FragTrap b("Steve");
	FragTrap a(b);

	a.meleeAttack("Frank");
	a.rangedAtack("Sandra");
	a.takeDamage(50);
	int i = 0;
	while (i++ < 7) {
		if (a.energy_points == 0) {
			a.beRepaired(100);
		}
		a.vaulthunter_dot_exe("Joe");
	}

	return 0;	
}