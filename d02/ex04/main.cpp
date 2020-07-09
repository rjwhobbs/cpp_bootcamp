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

void perform_add_min(Fixed& total, Fixed& a, char op) {
	if (op == '+'){
		total = total + a;
	} else if (op == '-'){
		total = total - a;
	} 
}


void perform_mul_div(Fixed& mult_total, Fixed& a, char op) {
	if (op == '*') {
		mult_total = mult_total * a;
	} else if (op == '/') {
		mult_total = mult_total / a;
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
	bool first_operand = false;

	is >> str;
	while(is) {
		std::cout << "F " << str << std::endl;

		if(!first_operand) {
			total = std::stof(str);
			first_operand = true;
		} 
		else if (first_operand) {

			if (is_float(str)) {
				a = std::stof(str);
				if (is_add_min(op)) {
					perform_add_min(total, a, op);
				}
				else if (is_mul_div(op)) {
					perform_mul_div(mult_total, a, op);
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
					mult_total.setRawBits(0x100);
					// await_op = 0; // ?is this needed 
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

	sum = get_val(is);
	std::cout << "Sum " << sum << std::endl;

	return 0;	
}