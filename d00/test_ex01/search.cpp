#include <cctype>
#include <string>
#include <iostream>
#include "Contact.class.hpp"
#include "phone_book.hpp"
#include "print.hpp"

static void print_search(std::string str) { //I need to checkout this automatic ref thing
	if (str.length() > 10) {
		str.erase(9, str.npos);
		str.push_back('.');
		print_str_pad(str, 10);
		return ;
	}
	print_str_pad(str, 10);
}

void search(Contact contacts[]) {

	int c = 0;
	
	if (!contacts[c].contact_empty()) {
		while (!contacts[c].contact_empty()) {
			print_search(contacts[c++].f_name);
		}
	} else {
		print_cstr_nl("There are no contacts to display.");
	}
}