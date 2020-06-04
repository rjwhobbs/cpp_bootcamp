#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string type, std::string name);
		~Zombie();

		void announce(void) const;
		void setType(std::string type);
		void setName(std::string name);

	private:
		std::string _type;
		std::string _name;
};

#endif