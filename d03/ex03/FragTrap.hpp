#ifndef FRAGTRAP_HPP	
#define FRAGTRAP_HPP	
#include <iostream>	
#include <string>
#include "ClapTrap.hpp"
	
class FragTrap : public ClapTrap {	
	public:	
		FragTrap(void);	
		FragTrap(std::string const name);	
		FragTrap(FragTrap const& src);	
		~FragTrap(void);	
		FragTrap& operator=(FragTrap const& rhs);	

		void vaulthunter_dot_exe(std::string const & target); 

	private:
		void (FragTrap::*randAttacks[5])(std::string const& target);
		void _flamingFartAttack(std::string const& target);
		void _flyingPianoAttack(std::string const& target);
		void _squirrelArmyAttack(std::string const& target);
		void _bakedInACakeAttack(std::string const& target);
		void _acidPancakeAttack(std::string const& target);

		static int _random_index(int max);
};

#endif