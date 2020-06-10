#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <string>
#include "Brain.hpp"

class Human : public Brain {
	
	Brain const brain;

	public:
		Human(void);
	 	~Human(void);

		std::string identify(void) const;
		Brain getBrain(void);
};

#endif