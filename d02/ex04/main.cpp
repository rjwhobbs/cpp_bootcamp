#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cctype>
#include "Fixed.hpp"

bool is_add_min(char op) {
	if (op == '+' || op == '-' ) {
		return true;
	}
	return false;
}

bool is_mul_div(char op) {
	if (op == '*' || op == '/' ) {
		return true;
	}
	return false;
}

bool is_op(std::string& str) {
	if (str.length() == 1 && (is_add_min(str[0]) || is_mul_div(str[0]))) {
		return true;
	}
	return false;
}

void perform_add_min(Fixed& sum, Fixed& b, char op) {
	if (op == '+'){
		sum = sum + b;
	} else if (op == '-'){
		sum = sum - b;
	} 
}


void perform_mul_div(Fixed& a, Fixed& b, char op) {
	if (op == '*') {
		b = a * b;
	} else if (op == '/') {
		b = a / b;
	}
	
}

void get_op(std::string& str, char* op) {
	switch (str[0]) {
		case '+' : *op = '+'; break;
		case '-' : *op = '-'; break;
		case '*' : *op = '*'; break;
		case '/' : *op = '/'; break;
	}
}

void reverse_prev(Fixed& sum, Fixed& b, char prev_op) {
	switch (prev_op) {
		case '+': sum = sum - b; break;
		case '-': sum = sum + b; break;
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

Fixed get_val(std::istringstream& is) {
	Fixed total;
	Fixed mult_total;
	Fixed a;

	std::string str;
	char op = 0;
	char await_op = 0;

	is >> str;
	while(is) {
		std::cout << "F " << str << std::endl;
		total = get_val(is);
	}

	return total;
}

int main(int ac, char* av[]) {
	(void)ac;
	std::istringstream is(av[1]);
	Fixed sum;

	sum = get_val(is);
	std::cout << "Sum " << sum << std::endl;

	return 0;	
}