#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	NinjaTrap a("Frank");
	FragTrap b("Snow Flake");
	ScavTrap c("Smelly Toes");
	NinjaTrap e("Donald Trump");

	a.ninjaShoebox(a);
	e.ninjaShoebox(a);
	a.ninjaShoebox(b);
	a.ninjaShoebox(c);

	return 0;	
}