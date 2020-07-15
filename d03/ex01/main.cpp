#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cstdlib>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	FragTrap b("Steve");
	// FragTrap a("Steve");
	FragTrap a(b);

	a.meleeAttack("Frank");
	a.rangedAtack("Sandra");
	a.takeDamage(50);

	int i = 0;
	while (i++ < 7) {
		if (a.energy_points == 0) {
			a.beRepaired(1);
		}
		a.vaulthunter_dot_exe("Joe");
	}

	ScavTrap x("Terres");
	// ScavTrap a("Steve");
	ScavTrap v(x);

	v.meleeAttack("Snow flake");
	v.rangedAtack("Cookie monster");
	v.takeDamage(50);

	i = 0;
	while (i++ < 7) {
		if (v.energy_points == 0) {
			v.beRepaired(1);
		}
		v.challengeNewcomer("Socks");
	}

	return 0;	
}