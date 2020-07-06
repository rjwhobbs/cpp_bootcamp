#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cctype>
#include "Fixed.hpp"

bool is_num(std::string& str) {
	Fixed a;
	Fixed b;
	size_t i = 0;
	while (i < str.length()) {
		if (!isdigit(str[i])) {
			return false;
		}
		i++;
	}
	return true;
}

int main(int ac, char* av[]) {
	Fixed a;
	Fixed b;
	Fixed sum;
	(void)ac;
	std::string input = av[1];
	std::istringstream is(input);
	
	char op = 0;
	bool stack = false;
	std::string str;
	int val = 0;
	is >> str;
	while(is) {
		std::cout << "Str " << str << std::endl;
		if (is_num(str) && !stack) {
			val = std::stoi(str);
			a = val;
			sum = sum + a;
			stack = true;	
		} else if (str == "+") {
			op = '+';
		} else if (is_num(str) && stack && op) {
			val = std::stoi(str);
			b = val;
			if (op == '+') {
				sum = sum + b;
			}
			op = 0;
		} 
		is >> str;
	}
	std::cout << "sum " << sum << std::endl;

	return 0;	
}