#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string, Weapon& weapon);
		~HumanA(void);

		void attack(void) const;

	private:
		std::string const _name;
		Weapon const& _weapon ; 
};

#endif