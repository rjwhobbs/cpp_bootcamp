#include <iostream>
#include "phone_book.hpp"

void print_str_nl(std::string &str) {
	std::cout << str << std::endl;
}

void print_str(std::string &str) {
	std::cout << str;
}

void print_cstr(const char *str) {
	std::cout << str;
}

void print_cstr_nl(const char *str) {
	std::cout << str << std::endl;
}