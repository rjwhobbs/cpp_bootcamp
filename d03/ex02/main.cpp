#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include "FragTrap.hpp"

int main(void) {
	FragTrap a("Mike");
	FragTrap b = a;
	FragTrap c(b);

	a.meleeAttack("Dog biscuit");
	a.rangedAtack("Cat biscuit");
	a.takeDamage(33);
	a.beRepaired(1);

	int i = 0;
	while (i++ < 5) {
		a.vaulthunter_dot_exe("Joe");
	}

	b.meleeAttack("Dog biscuit");
	b.rangedAtack("Cat biscuit");
	b.takeDamage(33);
	b.beRepaired(1);

	i = 0;
	while (i++ < 5) {
		b.vaulthunter_dot_exe("Joe");
	}

	c.meleeAttack("Dog biscuit");
	c.rangedAtack("Cat biscuit");
	c.takeDamage(33);
	c.beRepaired(1);

	i = 0;
	while (i++ < 5) {
		c.vaulthunter_dot_exe("Joe");
	}
	return 0;	
}