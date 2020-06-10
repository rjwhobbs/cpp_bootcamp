#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <sstream>

class Brain {

	public:
		Brain(void);
		~Brain(void);

		std::string identify(void) const;

	private:
		std::string _humanAddress;
};

#endif