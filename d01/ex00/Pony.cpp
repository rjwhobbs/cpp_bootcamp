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

std::string Pony::getName(void) const
{
	return this->_ponyName;
}