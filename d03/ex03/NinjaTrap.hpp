#ifndef NINJATRAP_HPP	
#define NINJATRAP_HPP	
#include <iostream>	
#include "ClapTrap.hpp"
	
class NinjaTrap : public ClapTrap {	
	public:	
		NinjaTrap(void);
		NinjaTrap(std::string& name);	
		NinjaTrap(NinjaTrap const& src);	
		NinjaTrap& operator=(NinjaTrap const& rhs);	
		~NinjaTrap(void);		
};	
#endif