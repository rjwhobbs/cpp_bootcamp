#include <string>
#include "Logger.hpp"

int main(void) {
	Logger logger("words");

	logger.logToConsole("word");

	return 0;
}