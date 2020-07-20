#ifndef PEON_HPP	
#define PEON_HPP	
#include <iostream>	
#include "Victim.hpp"
	
class Peon :
	public Victim {	

	public:
		Peon(std::string const name);	
		Peon(Peon const& src);	
		Peon& operator=(Peon const& rhs);	
		// ~Peon(void);	
	
	protected:	
		Peon(void);	
};	
#endif