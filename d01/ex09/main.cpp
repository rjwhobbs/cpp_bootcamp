#include <string>
#include <iostream>
#include <cstdlib>
#include "Logger.hpp"

int main(void) {
	Logger logger("log_file");

	logger.log("console", "words on the console");
	logger.log("file", "words in a file");

	// std::cout << itoa(1, buff, 10) << std::endl;
	// itoa(1, buff, 10);
	return 0;
}