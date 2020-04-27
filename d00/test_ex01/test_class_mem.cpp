#include <iostream>
#include <string> // this is already included in the hpp, so ya...
#include "User.class.hpp"

int	main(void) {
	
	User user[8];
	std::string temp;

	std::getline(std::cin, user[0].input); // I think this allocates mem, which may not be allowed.
	// from man: Each extracted character is appended to the string as if its member push_back was called. So maybe it's okay?

	std::cout << user[0].input << std::endl;

	return 0;
}
