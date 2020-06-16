#include <string>
#include <iostream>
#include "Human.hpp"

void Human::meleeAttack(std::string const& target) {
	std::cout << "Attacking " << target << " with a melee attack." << std::endl;
}

void Human::rangedAttack(std::string const& target) {
	std::cout << "Attacking " << target << " with a ranged attack." << std::endl;
}

void Human::intimidatingShout(std::string const& target) {
	std::cout << "Shouting at " << target << std::endl;
};

void Human::action(std::string const& action_name, std::string const& target) {
	std::string actions[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	void (Human::*actionMems[])(std::string const& target) = {
		&Human::meleeAttack, 
		&Human::rangedAttack, 
		&Human::intimidatingShout
	};

	int i = 0;
	while (i < 3) {
		if (actions[i] == action_name) {
			(this->*actionMems[i])(target);
		}
		i++;
	}
}