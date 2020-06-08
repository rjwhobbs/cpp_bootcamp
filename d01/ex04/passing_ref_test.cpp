#include <iostream>
#include <string>

void byPtr(std::string* str) {
	*str += " , and another one...";
	// std::cout << (*str).length() << std::endl;
}
void byRef(std::string& str) {
	str += " , and another one...";
	// std::cout << (*str).length() << std::endl;
}

int main(void) {
	std::string str_zero = "str_zero";
	std::string str_one = "str_onee";
	std::string str_two = "str_twoe";
	std::string str_three = "str_thre";

	byPtr(&str_zero);
	byRef(str_one);
	std::cout << *(&str_zero - 1) << std::endl;
	std::cout << &str_zero - 1 << std::endl;
	std::cout << &str_one << std::endl;
	std::cout << &str_one - 1 << std::endl;
	std::cout << &str_two << std::endl;
	std::cout << &str_two - 1  << std::endl;
	std::cout << &str_three << std::endl;

	std::cout << &str_zero -  &str_one << std::endl;
	std::cout << &str_one - &str_two << std::endl;
	std::cout << &str_two -  &str_three << std::endl;
	return 0;
}