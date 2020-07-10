#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cctype>
#include <system_error>
#include "Fixed.hpp"

void print_error(unsigned char error) {
	if (error & 01) {
		std::cerr << "Error: Can't divide by zero" << std::endl;
	}
}

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

void perform_add_min(Fixed& total, Fixed& a, char op) {
	if (op == '+'){
		total = total + a;
	} 
	else if (op == '-') {
		total = total - a;
	} 
}


void perform_mul_div(Fixed& mult_total, Fixed& a, char op, unsigned char* error) {
	if (op == '*') {
		mult_total = mult_total * a;
	} 
	else if (op == '/') {
		if (a == 0) {
			*error = 01;
		}
		else {
			mult_total = mult_total / a;
		}
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

void reverse_prev(Fixed& total, Fixed& a, char prev_op) {
	switch (prev_op) {
		case '+': total = total - a; break;
		case '-': total = total + a; break;
	}
}

bool is_float(std::string& str) {
	size_t i = 0;
	size_t len = str.length();
	while (i < len ) {
		if (!isdigit(str[i])) {
			if (i == 0 && (str[i] == '-' || str[i] == '+') && len > 1) {
				i++;
			}
			else if (str[i] == '.' && i < len - 1) {
				i++;
			} 
			else {
				return false;
			}
		} 
		else {
			i++;
		}
	}
	return true;
}

Fixed get_val(std::istringstream& is, unsigned char* error) {
	Fixed total;
	Fixed mult_total;
	Fixed a;
	Fixed rec;

	std::string str;
	char op = 0;
	char await_op = 0;
	bool first_operand = false;

	is >> str;
	while(is && str[0] != ')' && !*error) {
		// std::cout << "F " << str << ' ' << std::endl;

		if(!first_operand && ((is_float(str)) || str[0] == '(')) {
			if (str[0] != '(')	{
				total = std::stof(str);
			} 
			else if (str[0] == '(') {
				total = get_val(is, error);
			}
			first_operand = true;
		} 
		else if (first_operand) {

			if (is_float(str) || str[0] == '(') {
				if (str[0] != '(') {
					a = std::stof(str);
				} 
				else if (str[0] == '(') {
					a = get_val(is, error);
				}
				if (is_add_min(op)) {
					perform_add_min(total, a, op);
				}
				else if (is_mul_div(op)) {
					perform_mul_div(mult_total, a, op, error);
				}
			}
			else if (is_op(str)) {
				if (is_mul_div(str[0]) && (is_add_min(op) || !op)) {
					if (!op) {
						mult_total = total;
						total.setRawBits(0);
					} 
					else {
						reverse_prev(total, a, op);
						mult_total = a;
					}
					await_op = op;
				}
				else if (is_add_min(str[0]) && is_mul_div(op)) {
					if (is_add_min(await_op)) {
						perform_add_min(total, mult_total, await_op);
					} 
					else {
						perform_add_min(total, mult_total, '+');
					}
					mult_total.setRawBits(0);
				} 
				get_op(str, &op);
			}
		}
		is >> str;
	}

	if (await_op) {
		perform_add_min(total, mult_total, await_op);
	}
	else if (!await_op) {
		perform_add_min(total, mult_total, '+');
	}

	return total;
}

int main(int ac, char* av[]) {
	(void)ac;
	std::istringstream is(av[1]);
	Fixed sum;
	unsigned char error = 0;

	sum = get_val(is, &error);

	if (!error) {
		std::cout << "Answer " << sum << std::endl;
	}
	else {
		print_error(error);
	}

	return 0;	
}