#include <iostream>

int	main(void) {

	char buff[512];

	std::cout << "THESE are Words!" << std::endl;
	std::cout << "Type some: ";
	std::cin >> buff;
	std::cout << "This is what you typed: " << buff << std::endl;

	return (0);
}