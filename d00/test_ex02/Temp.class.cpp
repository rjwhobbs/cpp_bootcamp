#include <iostream>
#include "Temp.class.hpp"

// template<class T>
// Temp<T>::Temp(T i, T j) {
// 	this->a = i;
// 	this->b = j;

// 	return ;
// }
// Temp::Temp(void) {
// 	std::cout << "created" << std::endl;
// 	return ;
// }

Temp::~Temp(void) {
	std::cout << "destroyed" << std::endl;
	return ;
}

// void hackyHack() {
// 	Temp<int> temp(0, 0);
// }