#include "Pony.hpp"
#include <string>
#include <iostream>

Pony::Pony(std::string name) : _ponyName(name)
{
	std::cout << "A pony named " << this->getName() << " is born" << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << "A pony named " << this->getName() << " dies :(" << std::endl;
	return ;
}

void Pony::feedPony(std::string food) const
{
	if (food == "hamburger" || food == "Hamburger")
	{
		std::cout << "Yummy!" << std::endl;
	}
	else
	{
		std::cout << "Yuck, what is this..." << std::endl;
	}
}

std::string Pony::getName(void) const
{
	return this->_ponyName;
}