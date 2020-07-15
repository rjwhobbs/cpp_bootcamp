#ifndef FRAGTRAP_HPP	
#define FRAGTRAP_HPP	
#include <iostream>	
#include <string>
	
class FragTrap {	
	public:	
		FragTrap(void);	
		FragTrap(std::string const name);	
		FragTrap(FragTrap const& src);	
		~FragTrap(void);	
		FragTrap& operator=(FragTrap const& rhs);	

		void rangedAtack(std::string const& target);
		void meleeAttack(std::string const& target);
		void takeDamage(unsigned int amount); 
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target); 
	
		std::string name;

		unsigned int level;
		unsigned int hit_points;
		unsigned int max_hit_points;
		unsigned int energy_points;
		unsigned int max_energy_points;

		unsigned int melee_attack_dmg;
		unsigned int range_attack_dmg;
		unsigned int armor_dmg_reduction;

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