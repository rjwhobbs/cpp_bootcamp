#ifndef PEON_HPP	
#define PEON_HPP	
#include <iostream>	
	
class Peon {	
	public:	
		Peon(void);	
		Peon(Peon const& src);	
		~Peon(void);	
	
		Peon& operator=(Peon const& rhs);	
	
	private:	
};	
#endif