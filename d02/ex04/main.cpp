#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cctype>
#include "Fixed.hpp"

bool is_op(std::string& str) {
	if (str.length() == 1 && (str[0] == '+' || str[0] == '-')) {
		return true;
	}
	return false;
}

void perform_op(Fixed& sum, Fixed& b, char* op) {
	switch (*op) {
		case '+': sum = sum + b; break;
		case '-': sum = sum - b; break;
	}
}

void get_op(std::string& str, char* op) {
	switch (str[0]) {
		case '+' : *op = '+'; break;
		case '-' : *op = '-'; break;
	}
}

bool is_float(std::string& str) {
	size_t i = 0;
	while (i < str.length()) {
		if (!isdigit(str[i])) {
			if (str[i] == '.' && i < str.length() - 1) {
				i++;
			} else {
				return false;
			}
		} else {
			i++;
		}
	}
	return true;
}

int main(int ac, char* av[]) {
	(void)ac;
	Fixed a;
	Fixed b;
	Fixed sum;
	std::string input = av[1];
	std::istringstream is(input);
	
	char op = 0;
	bool first_operand = false;
	std::string str;
	float val = 0;
	
	is >> str;
	while(is) {
		std::cout << "Str " << str << std::endl;
		if (is_float(str) && !first_operand) {
			val = std::stof(str);
			a = val;
			sum = sum + a;
			first_operand = true;	
		} else if (is_op(str)) {
			get_op(str, &op);
		} else if (is_float(str) && first_operand && op) {
			val = std::stof(str);
			b = val;
			if (op) {
				perform_op(sum, b, &op);
			}
			op = 0;
		} 
		is >> str;
	}
	std::cout << "sum " << sum << std::endl;

	return 0;	
}