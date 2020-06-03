#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP
#include <string>
#include "Zombie.hpp"

class ZombieEvent {
	public:
		ZombieEvent();
		~ZombieEvent();

		void setZombieType(std::string type);
		Zombie* newZombie(std::string name);

	private:
		std::string _type;
};

#endif