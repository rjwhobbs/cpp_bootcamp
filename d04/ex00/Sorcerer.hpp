#ifndef SORCERER_HPP	
#define SORCERER_HPP	
#include <iostream>
#include <ostream>	
#include <string>
	
class Sorcerer {	
	public:	
		Sorcerer(std::string const name, std::string const title);
		Sorcerer(Sorcerer const& src);	
		Sorcerer& operator=(Sorcerer const& rhs);	
		~Sorcerer(void);

		std::string getName(void) const;
		std::string getTitle(void) const;

	private:
		Sorcerer(void);
		std::string _name;		
		std::string _title;		
};

std::ostream& operator<<(std::ostream& o, Sorcerer const& rhs);

#endif