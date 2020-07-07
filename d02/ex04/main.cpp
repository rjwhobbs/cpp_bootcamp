#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cctype>
#include "Fixed.hpp"

// void flip_op(char* prev_op, char* op) {
// 	switch (*op) {
// 		case '+': 
// 		case '-':
// 	}
// }

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

void perform_add_min(Fixed& sum, Fixed& b, char* op) {
	if (*op == '+'){
		sum = sum + b;
	} else if (*op == '-'){
		sum = sum - b;
	} 
}


void perform_mul_div(Fixed& sum, Fixed& a, Fixed& b, char* op, char* prev_op) {
	if (*op == '*') {
		b = a * b;
	} else if (*op == '/') {
		b = a / b;
	}
	if (is_add_min(*prev_op)) {
		perform_add_min(sum, b, prev_op);
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

void reverse_prev(Fixed& sum, Fixed& b, char* prev_op) {
	switch (*prev_op) {
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

int main(int ac, char* av[]) {
	(void)ac;
	Fixed a;
	Fixed b;
	Fixed sum;
	std::string input = av[1];
	std::istringstream is(input);
	
	char op = 0;
	char prev_op = 0;
	bool first_operand = false;
	std::string str;
	float val = 0;

	is >> str;
	while(is) {
		// std::cout << "Str " << str << std::endl;
		if (is_float(str) && !first_operand) {
			val = std::stof(str);
			a = val;
			sum = sum + a;
			first_operand = true;
			a.setRawBits(0);	
		} else if (is_op(str)) {
			get_op(str, &op);
			if (is_mul_div(op)) {
				reverse_prev(sum, b, &prev_op);
			}
		} else if (is_float(str) && first_operand && op) {
			val = std::stof(str);
			b = val;
	
			if (is_add_min(op)) {
				perform_add_min(sum, b, &op);
			} else if (is_mul_div(op)) {
				perform_mul_div(sum, a, b, &op, &prev_op);
			}
			prev_op = op;
			a = b;
			op = 0;
		} 
		is >> str;
		std::cout << "sum " << sum << std::endl;
	}

	return 0;	
}