#include <string>
#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() : _type("default") {
	return ;
}

ZombieEvent::~ZombieEvent() {
	return ;
}

void ZombieEvent::setZombieType(std::string type) {
	this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
	Zombie* freshZombie = new Zombie(this->_type, name); 
	return freshZombie;
}
