#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <string>
#include "Brain.hpp"

class Human : public Brain {

	public:
		Human();
	 	~Human(void);

		std::string identify(void) const;
		Brain& getBrain(void);

	private:
		Brain _brain;

};

#endif