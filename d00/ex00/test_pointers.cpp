#include <iostream>
#include "Simple.class.hpp"

int	main(void) {
	Simple sim;
	Simple* simP = &sim;

	int	Simple::*p;
	void (Simple::*f)(void) const;

	f = &Simple::bar; // These seem like the main diff between c and cpp
	p = &Simple::foo;

	sim.*p = 42;
	std::cout << sim.foo << std::endl;
	simP->*p = 9000;
	std::cout << sim.foo << std::endl;


	(sim.*f)();
	(simP->*f)();
	
	return 0;
}