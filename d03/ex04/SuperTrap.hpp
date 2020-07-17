#ifndef SUPERTRAP_HPP	
#define SUPERTRAP_HPP	
#include <iostream>	
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
	
class SuperTrap : 
	public FragTrap, 
	public NinjaTrap {

	public:	
		SuperTrap(void);	
		SuperTrap(std::string const name);
		SuperTrap(SuperTrap const& src);	
		SuperTrap& operator=(SuperTrap const& rhs);	
		~SuperTrap(void);	
	
};	
#endif