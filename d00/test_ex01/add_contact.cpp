#include <string>
#include <iostream>
#include "Contact.class.hpp"
#include "phone_book.hpp"
#include <cctype>

static void print_str_nl(std::string &str) {
	std::cout << str << std::endl;
}

static void print_str(std::string &str) {
	std::cout << str;
}

static void print_cstr(const char *str) {
	std::cout << str;
}
static void print_cstr_nl(const char *str) {
	std::cout << str << std::endl;
}

static int no_space(std::string &str) {
	size_t i = 0;
	while (i < str.length()) {
		if (isspace(str[i++])) {
			return 0;
		}
	}
	return 1;
}

static void print_command(int i) {
	switch (i) {
		case 0: print_cstr("Please enter your first name: "); break;
		case 1: print_cstr("Please enter your last name: "); break;
		case 2: print_cstr("Please enter your nick name: "); break;
		case 3: print_cstr("Please enter your login name: "); break;
	}
}

void add_contact(Contact &contact) {
	std::string temp;
	int inp_count = 0;
	
	while (inp_count < 4) {
		print_command(inp_count);
		std::getline(std::cin, temp);
		if (!temp.empty() && no_space(temp)) {
			switch(inp_count) {
				case 0: contact.f_name = temp; break;
				case 1: contact.l_name = temp; break;
				case 2: contact.nick_name = temp; break;
				case 3: contact.login_name = temp; break;

			}
			inp_count++;
		} else {
			print_cstr_nl("You entry can't be empty.");
		}
	}
}