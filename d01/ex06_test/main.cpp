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
		Weapon w = Weapon("ray gun");
		HumanA bob("bob", w);
		bob.attack();
		w.setType("Tomato");
		bob.attack();
	}
	{
		Weapon w = Weapon("club");
		HumanB jim = HumanB("jim");
		jim.attack();
		jim.setWeapon(w);
		jim.attack();
		w.setType("potato");
		jim.attack();
	}
	return 0;
}