#ifndef SCAVTRAP_HPP	
#define SCAVTRAP_HPP	
#include <iostream>	
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {	
	public:	
		ScavTrap(void);
		ScavTrap(std::string const name);		
		ScavTrap(ScavTrap const& src);	
		ScavTrap& operator=(ScavTrap const& rhs);	
		~ScavTrap(void);	

		void challengeNewcomer(std::string const& target);
	
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