#ifndef VICTIM_HPP	
#define VICTIM_HPP	
#include <iostream>	
	
class Victim {	
	public:
		Victim(std::string const name);	
		Victim(Victim const& src);	
		Victim& operator=(Victim const& rhs);	
		~Victim(void);	

		std::string getName(void) const;
		void getPolymorphed(void) const;
	
	protected:
		Victim(void);	
		std::string _name;	
};

std::ostream& operator<<(std::ostream& o, Victim const& rhs);

#endif