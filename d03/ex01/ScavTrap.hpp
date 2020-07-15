#ifndef SCAVTRAP_HPP	
#define SCAVTRAP_HPP	
#include <iostream>	
	
class ScavTrap {	
	public:	
		ScavTrap(void);	
		ScavTrap(ScavTrap const& src);	
		~ScavTrap(void);	
	
		ScavTrap& operator=(ScavTrap const& rhs);	
	
	private:	
};	
#endif