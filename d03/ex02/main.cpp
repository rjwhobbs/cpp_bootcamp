#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	FragTrap a("Mike");
	FragTrap b = a;
	FragTrap c(b);

	ScavTrap e("Cheese Cake");
	ScavTrap f = e;
	ScavTrap g(f);

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
	b.vaulthunter_dot_exe("Joe");

	c.meleeAttack("Dog biscuit");
	c.rangedAtack("Cat biscuit");
	c.takeDamage(33);
	c.beRepaired(1);
	c.vaulthunter_dot_exe("Joe");

	e.meleeAttack("Dog biscuit");
	e.rangedAtack("Cat biscuit");
	e.takeDamage(33);
	e.beRepaired(1);

	i = 0;
	while (i++ < 5) {
		e.challengeNewcomer("Face");
	}

	f.meleeAttack("Dog biscuit");
	f.rangedAtack("Cat biscuit");
	f.takeDamage(33);
	f.beRepaired(1);
	f.challengeNewcomer("Toast");

	g.meleeAttack("Dog biscuit");
	g.rangedAtack("Cat biscuit");
	g.takeDamage(33);
	g.beRepaired(1);
	g.challengeNewcomer("Fiz");

	return 0;	
}