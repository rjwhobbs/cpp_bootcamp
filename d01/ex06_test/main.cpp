#include <iostream>
#include <string>
#include "Weapon.hpp"

void f(Weapon& w) {
	w.setType("wet fish");
	return;
}

int main(void) {
	Weapon w = Weapon("club");

	std::cout << w.getType() << std::endl;
	f(w);
	std::cout << w.getType() << std::endl;
	return 0;
}