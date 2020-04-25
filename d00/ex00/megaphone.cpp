#include <iostream>
#include <cctype>

void toupper_fn(char &c) { // So it looks like cpp can decide to pass by ref or val. See for_each man cpp
	c = toupper(c);
}

// This takes all the concatinated args and strips the unnecessary white space, not sure if that's required
std::string new_str(std::string &str) {
	std::string new_string = "";
	size_t start = 0;
	size_t end = 0;

	if (start != str.npos) {
		while (start != str.npos) {
			while (start < str.length() && isspace(str[start])) {
				start++;
			}
			end = str.find_first_of(" \t\n\r\f", start);
			if (end != str.npos) {
				new_string += str.substr(start, end - start);
				new_string += ' ';
			} else {
				if (start != str.length()) {
					new_string += str.substr(start, str.length() - start);
				}
				if (!new_string.empty() && isspace(new_string[new_string.length() - 1])) {
					new_string.pop_back();
				}
				return new_string;
			}
			start = str.find_first_of(" \t\n\r\f", end);
		}
	}
	return str;
}

int main(int ac, char *av[]) {

	std::string default_str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1) {
		std::cout << default_str << std::endl;
		return (0);
	}

	size_t len;
	size_t i;
	int c = 1;
	std::string args;

	while (c < ac) {
		args += av[c];
		if (c < ac - 1) {
			args += ' ';
		}
		c++;
	}
	// std::cout << args << std::endl; 
	args = new_str(args); //  thid is weird but hey cpp

	len = args.length();

	if (!len) {
		std::cout << default_str << std::endl;
		return (0);
	}

	i = 0;
	while (i < len) {
		toupper_fn(args[i++]);
	}

	std::cout << args << std::endl;

	return (0);
}