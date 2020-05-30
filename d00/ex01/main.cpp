#include <iostream>
#include <string> // this is already included in the hpp, so ya...
#include "phone_book.hpp"
#include "Contact.class.hpp"
#include "print.hpp"

// Every output must go to newline?
int	main(void) {
	
	Contact contacts[8];
	std::string command;

	int i = 0;

	print_cstr_nl("Welcome to this amazing contact app.");

	while (1) {
		print_cstr_nl("Main menu options: ADD, SEARCH, EXIT.");
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
			print_cstr_nl("Option not recognised.");
		}
	}

	return 0;
}
