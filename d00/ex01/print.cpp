#include <iostream>
#include <iomanip> 
#include "phone_book.hpp"

void print_str_nl(std::string &str) {
	std::cout << str << std::endl;
}

void print_str(std::string &str) {
	std::cout << str << std::flush;
}

void print_cstr(const char *str) {
	std::cout << str << std::flush;
}

void print_cstr_nl(const char *str) {
	std::cout << str << std::endl;
}

void print_str_pad(std::string str, int pad) {
	std::cout << std::setw(pad);
	std::cout << str << std::flush;
}

void print_str_pad_nl(std::string str, int pad) {
	std::cout << std::setw(pad);
	std::cout << str << std::endl;
}

void print_cstr_pad(const char *str, int pad) {
	std::cout << std::setw(pad);
	std::cout << str << std::flush;
}

void print_cstr_pad_nl(const char *str, int pad) {
	std::cout << std::setw(pad);
	std::cout << str << std::endl;
}