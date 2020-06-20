#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

int main(int ac, char* av[]) {
	char c;
	int i = 0;
	// So while get() doesn't encounter a delimiter
	// cout carries on buffering it's stream,
	// once get() encounters a delimiter does it
	// release cout?
	// Seems like there are too things going on,
	// The while loop and std::cin.get() retruning a
	// a value other than null?
	while (std::cin.get(c)) {
		std::cout << i++;
		std::cout << c;
	};

	std::cout << i << std::endl;

	if (std::cin.eof()) {
		std::cout << "XXXX";
	}

  // std::cout << "Please, enter your full name: ";
  // if (std::getline (std::cin,name).eof()) {
	// 	std::cout << "YOOO";
	// };
  // std::cout << "Hello, " << name << "!\n";


	return 0;
}