#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

int Contact::contact_empty(void) const {
	if (this->f_name.empty() || 
			this->l_name.empty() ||
			this->nick_name.empty() ||
			this->login_name.empty() ||
			this->postal_addr.empty() ||
			this->email_addr.empty() ||
			this->ph_num.empty() ||
			this->birth_date.empty() ||
			this->fav_meal.empty() ||
			this->uw_colour.empty() ||
			this->d_secrect.empty()) {
		return 1;
	}
	return 0;
}

void Contact::print_all_info(void) const {
	std::cout << "First name       : " + this->f_name << std::endl;
	std::cout << "Last name        : " + this->l_name << std::endl;
	std::cout << "Nickname         : " + this->nick_name << std::endl;
	std::cout << "login name       : " + this->login_name << std::endl;
	std::cout << "Postal address   : " + this->postal_addr << std::endl;
	std::cout << "Email address    : " + this->email_addr << std::endl;
	std::cout << "Phone number     : " + this->ph_num << std::endl;
	std::cout << "Birth date       : " + this->birth_date << std::endl;
	std::cout << "Favourite meal   : " + this->fav_meal << std::endl;
	std::cout << "Underwear colour : " + this->uw_colour << std::endl;
	std::cout << "Darkest secret   : " + this->d_secrect << std::endl;
}