#include <cctype>
#include <string>
#include <iostream>
#include "Contact.class.hpp"
#include "phone_book.hpp"
#include "print.hpp"

//Need to debug this func
int only_digits(std::string &str) {
	size_t c = 0;

	while (c < str.length()) {
		if (!isdigit(str[c])) {
			return 0;
		}
		c++;
	}
	return 1;
}

static void print_heading(void) {
	print_cstr("index");
	print_cstr(" | ");
	print_cstr_pad("first name", 10);
	print_cstr(" | ");
	print_cstr_pad("last name", 10);
	print_cstr(" | ");
	print_cstr_pad_nl("nickname", 10);
}

static void print_feild(std::string str) { //I need to checkout this automatic ref thing
	if (str.length() > 10) {
		str.erase(9, str.npos);
		str.push_back('.');
		print_str_pad(str, 10);
		return ;
	}
	print_str_pad(str, 10);
}

void print_index(Contact contacts[], int index_max) {
	int index = -1;
	std::string input = "";
	
	while (1) {
		print_cstr("Enter the index you would like to view: ");
		std::getline(std::cin, input);

		if (input != "MENU") {
			if (!input.empty() && input.length() < 2 && only_digits(input)) {
				index = std::stoi(input, NULL, 10) - 1;
			}
			if (index >= 0 && index <= index_max) {
				contacts[index].print_all_info();
				index = -1;
				input.clear();
			} else {
				print_cstr_nl("Only enter a valid index, or type MENU to return to the main menu.");
			}
		} else {
			return ;
		}
	}
}

// Could probably pass by ref here
void search(Contact contacts[]) {

	int c = 0;
	
	if (!contacts[c].contact_empty()) {
		print_heading();
		while (!contacts[c].contact_empty() && c < 8) {
			print_str_pad(std::to_string(c + 1), 5);
			print_cstr("   ");
			print_feild(contacts[c].f_name);
			print_cstr("   ");
			print_feild(contacts[c].l_name);
			print_cstr("   ");
			print_feild(contacts[c].nick_name);
			print_cstr("\n");
			c++;
		}
		print_index(contacts, c - 1);
	} else {
		print_cstr_nl("There are no contacts to display.");
	}
}