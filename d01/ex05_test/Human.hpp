#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Brain.hpp"

class Human : public Brain {
	
	Brain const brain;

	public:
		Human(void);
	 	~Human(void);

		Brain getBrain(void) const;
};

#endif