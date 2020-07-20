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
		virtual void getPolymorphed(void) const;
	
	protected:
		std::string _name;	
		Victim(void);	
};

std::ostream& operator<<(std::ostream& o, Victim const& rhs);

#endif