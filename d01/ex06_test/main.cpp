#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

void f(Weapon& w) {
	w.setType("wet fish");
	return;
}

int main(void) {
	{
		Weapon w = Weapon("club");
		HumanA bob("bob", w);
		bob.attack();
		w.setType("potato");
		bob.attack();
	}
	{
		Weapon w = Weapon("club");
		HumanB jim("jim");
		jim.setWeapon(w);
		jim.attack();
		w.setType("potato");
		jim.attack();
	}
	return 0;
}