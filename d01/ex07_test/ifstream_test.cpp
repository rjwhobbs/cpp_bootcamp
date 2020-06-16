#include <sstream>
#include <iostream>
#include <fstream>
#include <cctype>

bool isNonWord(char c) {
	if (!isalnum(c) && c != '_') {
		return true;
	}
	return false;
}

int main(void) {
	std::string find = "me";
	std::string replace = "thmeis";
	std::stringstream streamBuf;
	std::string tempStr;
	std::ifstream ifs("test.txt");

	streamBuf << ifs.rdbuf();
	tempStr = streamBuf.str();

	size_t pos = tempStr.find(find, 0);
	while (pos != std::string::npos) {
		tempStr.replace(pos, find.length(), replace);
		pos = tempStr.find(find, pos + replace.length());
	}

	std::cout << tempStr << std::endl;


	// std::ofstream ofs("");

	ifs.close();
	// ofs.close();
	return 0;
}