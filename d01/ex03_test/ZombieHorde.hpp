#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP
#include <string>
#include "Zombie.hpp"

class ZombieHorde {

	public:
		ZombieHorde(int numZombies);
		~ZombieHorde();

		void announce(void) const;

	private:
		int _randIndex(int max) const;
		std::string _zombieNameGen(int index) const;

		Zombie* _zombies;
		int const _numZombies;
};

#endif