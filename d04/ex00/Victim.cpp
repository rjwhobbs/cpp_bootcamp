#include <iostream>	
#include "Victim.hpp"	
	
Victim::Victim (void) {	
}	
	
Victim::Victim (Victim const& src) {	
}	
	
Victim::~Victim (void) {	
}	
	
Victim& Victim::operator=(Victim const& rhs) {	
	(void)rhs;	
	return *this;	
}