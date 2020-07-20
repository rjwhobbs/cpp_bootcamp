#ifndef VICTIM_HPP	
#define VICTIM_HPP	
#include <iostream>	
	
class Victim {	
	public:	
		Victim(void);	
		Victim(Victim const& src);	
		~Victim(void);	
	
		Victim& operator=(Victim const& rhs);	
	
	private:	
};	
#endif