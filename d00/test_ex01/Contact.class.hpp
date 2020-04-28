#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <string>

class Contact {
	public:
	Contact(void);
	~Contact(void);

	std::string f_name;
	std::string l_name;
	std::string nick_name;
	std::string login_name;
	std::string postal_addr;
	std::string email_addr;
	std::string ph_num;
	std::string birth_date;
	std::string fav_meal;
	std::string uw_color;
	std::string d_secrect;
};

#endif