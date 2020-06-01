#ifndef PONY_HPP
#define PONY_HPP
#include <string>

class Pony
{
public:
	Pony(std::string name);
	~Pony();

	std::string getName(void) const;

private:
	std::string const _ponyName;
};

#endif