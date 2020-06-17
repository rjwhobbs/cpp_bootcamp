#include <string>
#include <iostream>
#include <cstdlib>
#include "Logger.hpp"

int main(void) {
	Logger logger("words");
	char buff[10];

	logger.logToConsole("word");

	// std::cout << itoa(1, buff, 10) << std::endl;
	// itoa(1, buff, 10);
	return 0;
}