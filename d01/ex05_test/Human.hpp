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
		int getX(void);

	private:
		Brain _brain;
		int _x;

};

#endif