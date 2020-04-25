#include <iostream>
#include <cctype>

void toupper_fn(char &c) { // So it looks like cpp can decide to pass by ref or val. See for_each man cpp
	c = toupper(c);
}

std::string split(std::string &str) {
	std::string temp = "";
	size_t start = str.find_first_of(" \t\n\r\f");
	size_t end = 0;

	if (start != str.npos) {
		while (start != str.npos) {
			while (isspace(str[start]) && start != str.length()) {
				start++;
			}
			end = str.find_first_of(" \t\n\r\f", start);
			if (end != str.npos) {
				temp += str.substr(start, end - start);
				temp += ' ';
			} else {
				temp += str.substr(start, str.length() - start);
				if (isspace(str[str.length() - 1])) {
					temp.pop_back();
				}
				return temp;
			}
			start = str.find_first_of(" \t\n\r\f", end);
		}
	}
	return temp;
}

int main(int ac, char *av[]) {

	if (ac == 1) {
		return (0);
	}

	// size_t j = 0;
	std::string temp = av[1];

	std::string test = split(temp);

	std::cout << test << std::endl;

	// while (isspace(temp[j]) != 0) {
	// 	temp.erase(j, 1);
	// 	printf("x\n");
	// }
	// std::cout << temp << std::endl;

	// std::string args = av[1];
	// size_t i = args.length();
	// std::cout << i << std::endl;
	// args.erase(0, 1);
	// std::cout << args.length() << std::endl;
	// std::cout << args[i] << std::endl;

	return (0);
}