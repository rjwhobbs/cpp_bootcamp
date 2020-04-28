#include <string>
#include <iostream>
#include "Contact.class.hpp"
#include "phone_book.hpp"
#include <cctype>

static int no_space(std::string &str) {
	size_t i = 0;
	while (i < str.length()) {
		if (isspace(str[i++])) {
			return 0;
		}
	}
	return 1;
}

void add_contact(Contact &contact) {
	std::string temp;
	int inp_count = 0;
	std::getline(std::cin, temp);
	if (!temp.empty() && no_space(temp)) {
		contact.f_name = temp;
	} else {
		printf("XXX");
	}
}