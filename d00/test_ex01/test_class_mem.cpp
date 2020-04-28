#include <iostream>
#include <string> // this is already included in the hpp, so ya...
#include "phone_book.hpp"
#include "Contact.class.hpp"

void print_nl(std::string &str) {
	std::cout << str << std::endl;
}

int	main(void) {
	
	Contact contacts[8];
	std::string command;

	// int i = 0;

	while (command != "EXIT") {
		std::cout << "Type EXIT to well, exit: ";
		std::getline(std::cin, command);
		if (command == "ADD") {
			add_contact(contacts[0]);
		}
		// print_nl(command);
	}

	std::cout << contacts[0].f_name << std::endl;

	return 0;
}
