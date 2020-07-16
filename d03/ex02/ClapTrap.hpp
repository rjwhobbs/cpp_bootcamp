#ifndef CLAVTRAP_HPP	
#define CLAVTRAP_HPP	
#include <iostream>	
	
class ClapTrap {	
	public:	
		ClapTrap(void);	
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const& src);	
		ClapTrap& operator=(ClapTrap const& rhs);	
		~ClapTrap(void);	
		
		void rangedAtack(std::string const& target);
		void meleeAttack(std::string const& target);
		void takeDamage(unsigned int amount); 
		void beRepaired(unsigned int amount);

		std::string name;

		unsigned int level;
		unsigned int hit_points;
		unsigned int max_hit_points;
		unsigned int energy_points;
		unsigned int max_energy_points;
		unsigned int melee_attack_dmg;
		unsigned int range_attack_dmg;
		unsigned int armor_dmg_reduction;
			
};	
#endif