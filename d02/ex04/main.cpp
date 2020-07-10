#include <cstdio>
#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include <cctype>
#include <system_error>
#include "Fixed.hpp"

void print_error(char error) {
	if (error & 01) {
		std::cerr << "Error: Can't divide by zero" << std::endl;
	}
	if (error & 02) {
		std::cerr << "Syntax error: Operators and operands need to be space seperated " << std::endl;
	}
	if (error & 04) {
		std::cerr << "Error: Only use numeric values" << std::endl;
	}
}

void check_str(std::string& str, char* error) {
	size_t len = str.length();
	if ((str[0] == '(' || str[0] == ')') && len > 1 ) {
		*error += 02; 
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


void perform_mul_div(Fixed& mult_total, Fixed& a, char op, char* error) {
	if (op == '*') {
		mult_total = mult_total * a;
	} 
	else if (op == '/') {
		if (a == 0) {
			*error += 01;
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

Fixed eval_expr(std::istringstream& is, char* error) {
	Fixed total;
	Fixed mult_total;
	Fixed a;
	Fixed rec;

	std::string str;
	char op = 0;
	char await_op = 0;
	bool first_operand = false;

	is >> str;
	check_str(str, error);
	while (is && str != ")" && !*error) {
		std::cout << "F " << str << ' ' << std::endl;

		if (!first_operand && (is_float(str) || str == "(")) {
			if (str != "(")	{
				total = std::stof(str);
			} 
			else if (str == "(") {
				total = eval_expr(is, error);
			}
			first_operand = true;
		} 
		else if (first_operand) {
			if (is_float(str) || str == "(") {
				if (str != "(") {
					a = std::stof(str);
				} 
				else if (str == "(") {
					a = eval_expr(is, error);
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
		check_str(str, error);
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
	char error = 0;

	sum = eval_expr(is, &error);

	if (!error) {
		std::cout << "Answer " << sum << std::endl;
	}
	else {
		print_error(error);
	}

	return 0;	
}