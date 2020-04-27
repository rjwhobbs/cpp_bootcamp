#include <iostream>
#include <string>

int	main(void) {

	std::string mystring = "THESE are Words! " "And these";
	char buff[512];
	float x (123.123);
	decltype(x) y = 321.321;

	std::cout << mystring << std::endl;
	std::cout << (mystring =  "Type some: ");
	std::cin >> buff;
	std::cout << x << ' ' << y << ' ' << buff << std::endl; //This takes care of \n char output on different systems

	return (0);
}