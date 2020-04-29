#include <iostream>
#include <string> // this is already included in the hpp, so ya...
#include "phone_book.hpp"
#include "Contact.class.hpp"
#include "print.hpp"

int	main(void) {
	
	Contact contacts[8];
	std::string command;

	int i = 0;

	print_cstr_nl("Welcome to this amazing contact app.");
	print_cstr_nl("Available options: ADD, SEARCH, EXIT.");

	while (command != "EXIT") {
		std::getline(std::cin, command);
		if (command == "ADD") {
			if (i < 8) {
				add_contact(contacts[i++]);
			} else {
				print_cstr_nl("You can only add 8 contacts to this contact book");
			}
		} else if (command == "SEARCH") {
			search(contacts);
		} else if (command == "EXIT") {
			return 0;
		} 
		else {
			print_cstr_nl("Option not recognised please try ADD, SEARCH, or EXIT.");
		}
	}

	// std::cout << contacts[0].f_name << std::endl;
	// std::cout << contacts[0].l_name << std::endl;
	// std::cout << contacts[0].nick_name << std::endl;
	// std::cout << contacts[0].login_name << std::endl;

	return 0;
}
