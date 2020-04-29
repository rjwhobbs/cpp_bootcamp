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