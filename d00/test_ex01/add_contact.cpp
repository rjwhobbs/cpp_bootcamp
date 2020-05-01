#include <string>
#include <iostream>
#include <cctype>
#include "Contact.class.hpp"
#include "phone_book.hpp"
#include "print.hpp"

static int no_space(std::string &str) {
	size_t i = 0;
	size_t check = 0;

	while (i < str.length()) {
		if (isspace(str[i++])) {
			check++;
		}
	}
	if (check == i) {
		return 0;
	}
	return 1;
}
// What will switch case do if the number isn't found
static void print_command(int i) {
	switch (i) {
		case 0: print_cstr("Please enter your first name: "); break;
		case 1: print_cstr("Please enter your last name: "); break;
		case 2: print_cstr("Please enter your nick name: "); break;
		case 3: print_cstr("Please enter your login name: "); break;
		case 4: print_cstr("Please enter your postal address: "); break;
		case 5: print_cstr("Please enter your email address: "); break;
		case 6: print_cstr("Please enter your phone number: "); break;
		case 7: print_cstr("Please enter your birth date: "); break;
		case 8: print_cstr("Please enter your favourite meal: "); break;
		case 9: print_cstr("Please enter your underwear colour: "); break;
		case 10: print_cstr("Please enter your darkest secret: "); break;
	}
}

void add_contact(Contact &contact) {
	std::string temp;
	int inp_count = 0;
	
	while (inp_count < 11) {
		print_command(inp_count);
		std::getline(std::cin, temp);
		if (!temp.empty() && no_space(temp)) {
			switch(inp_count) {
				case 0: contact.f_name = temp; break;
				case 1: contact.l_name = temp; break;
				case 2: contact.nick_name = temp; break;
				case 3: contact.login_name = temp; break;
				case 4: contact.postal_addr = temp; break;
				case 5: contact.email_addr = temp; break;
				case 6: contact.ph_num = temp; break;
				case 7: contact.birth_date = temp; break;
				case 8: contact.fav_meal = temp; break;
				case 9: contact.uw_colour = temp; break;
				case 10: contact.d_secrect = temp; break;
			}
			inp_count++;
		} else {
			temp.clear();
			print_cstr_nl("You entry can't be empty.");
		}
	}
}