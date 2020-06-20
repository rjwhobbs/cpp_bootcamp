#include <cstdio>
#include <fstream>
#include <streambuf>
#include <string>
#include <iostream>
#include <sstream>
#include <string_view>

int main(int ac, char* av[]) {
	std::stringbuf sstr;
	int i = 0;

	while (std::cin.get(sstr)) {
		i++;
		std::cout << sstr.str();
	};

	std::cout << i << std::endl;

	if (std::cin.eof()) {
		std::cout << "XXXX";
	}

	return 0;
}