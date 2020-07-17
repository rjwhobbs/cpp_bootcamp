#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "SuperTrap.hpp"

int main(void) {
	SuperTrap a("FLEX BOX");
	NinjaTrap b("Shiny shoe");
	
	a.vaulthunter_dot_exe("CHOP");
	a.ninjaShoebox(b);

	return 0;	
}