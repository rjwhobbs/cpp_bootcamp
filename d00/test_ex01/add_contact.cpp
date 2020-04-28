#include <string>
#include <iostream>
#include "Contact.class.hpp"
#include "phone_book.hpp"

void add_contact(Contact &contact) {
	std::getline(std::cin, contact.f_name);
}