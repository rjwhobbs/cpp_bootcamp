#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include "FragTrap.hpp"

int main(void) {
	FragTrap a("Joe");
	FragTrap b(a);

	std::cout << b.name << std::endl;

	return 0;	
}