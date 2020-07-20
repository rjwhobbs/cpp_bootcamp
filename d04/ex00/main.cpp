#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include "Sorcerer.hpp"
#include "Victim.hpp"

int main(void) {	
	Sorcerer steve("Steve", "the Most BadAss");
	Victim tom("Tom");

	std::cout << steve << tom;

	steve.polymorph(tom);
	return 0;	
}