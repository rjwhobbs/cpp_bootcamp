#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
	public:
		Zombie(std::string type, std::string name);
		~Zombie();

		void announce(void) const;

	private:
		std::string const _type;
		std::string const _name;
};

#endif