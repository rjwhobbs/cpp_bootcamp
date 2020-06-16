#include <cstdlib>
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

// Is it possible that they are asking to create a unique file to write the contents too?
// The pdf never makes sense

int main(int ac, char* av[]) {
	if (ac < 4) {
		std::cerr << "Usage error: <filename> <find> <replace>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string find = av[2];
	std::string replace = av[3];
	std::stringstream streamBuf;
	std::string tempStr;
	std::ifstream ifs(av[1], std::ifstream::out);

	if (ifs.fail()) {
		std::cerr << "Error reading file.\nEnsure that the path is correct and that you have correct permissions." << std::endl;
		return EXIT_FAILURE;
	}

	streamBuf << ifs.rdbuf();
	tempStr = streamBuf.str();

	size_t pos = tempStr.find(find, 0);
	while (pos != std::string::npos) {
		if (pos > 0) {
			if (isNonWord(tempStr[pos - 1]) && 
					isNonWord(tempStr[find.length() + pos])) 
			{
				tempStr.replace(pos, find.length(), replace);
				pos = tempStr.find(find, pos + replace.length());
			} else {
				pos = tempStr.find(find, pos + find.length());
			}
		} else if (pos == 0) {
			if (isNonWord(tempStr[find.length()])) {
				tempStr.replace(pos, find.length(), replace);
				pos = tempStr.find(find, pos + replace.length());
			} else {
				pos = tempStr.find(find, pos + find.length());
			}
		}
	}

	std::ofstream ofs("test.txt", std::ofstream::trunc);
	ofs << tempStr;

	ifs.close();
	ofs.close();
	return 0;
}