#ifndef SCAVTRAP_HPP	
#define SCAVTRAP_HPP	
#include <iostream>	
	
class ScavTrap {	
	public:	
		ScavTrap(void);
		ScavTrap(std::string const name);		
		ScavTrap(ScavTrap const& src);	
		~ScavTrap(void);	
		ScavTrap& operator=(ScavTrap const& rhs);	

		void rangedAtack(std::string const& target);
		void meleeAttack(std::string const& target);
		void takeDamage(unsigned int amount); 
		void beRepaired(unsigned int amount);
		void challengeNewcomer(std::string const& target);

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
		void (ScavTrap::*randomChallenges[5])(std::string const& target);
		void _playScrabbleChallenge(std::string const& target);
		void _eatMarshmelloChallenge(std::string const& target);
		void _burpingChallenge(std::string const& target);
		void _gameOfSkateChallenge(std::string const& target);
		void _codingChallenge(std::string const& target);

		static int _random_index(int max);
};	
#endif