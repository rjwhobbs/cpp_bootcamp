#ifndef NINJATRAP_HPP	
#define NINJATRAP_HPP	
#include <iostream>	
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
	
class NinjaTrap : public ClapTrap {	
	public:	
		NinjaTrap(void);
		NinjaTrap(std::string const name);	
		NinjaTrap(NinjaTrap const& src);	
		NinjaTrap& operator=(NinjaTrap const& rhs);	
		~NinjaTrap(void);		

		void ninjaShoebox(NinjaTrap const& target);
		void ninjaShoebox(FragTrap const& target);
		void ninjaShoebox(ScavTrap const& target);
};	
#endif