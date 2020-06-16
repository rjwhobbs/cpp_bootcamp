#include "Human.hpp"
#include <cstdlib>

int main(void) {
	Human pete;

	pete.action("meleeAttack", "a potato");
	pete.action("rangedAttack", "a potato");
	pete.action("intimidatingShout", "a potato");

	return EXIT_SUCCESS;
}