#include <iostream>
#include <string>
#include <sstream>
#include "Brain.hpp"
#include "Human.hpp"

Human::Human() : _x(99) {
	return ;
}

Human::~Human(void) {
	return ;
}

int Human::getX(){
	std::cout << &(this->_x) << std::endl;
	return this->_x;
}

std::string Human::identify(void) const {
	return this->_brain.identify();
}

// This is what I think was happening.
// When returning Brain instead of Brain&
// I was returning a value, ie not a reference,
// I was returning by value, think of 
// Brain as a data-type, like if you had
// to return a c string, yeah sure you 
// would get your string but if you 
// were returning it by value it would have 
// a different address each time ,so when I was saying, 
// "Hey get me your address" it was 
// just returning the address of the new value
// in main.
// So lets look at our example of _x here.
// I'm only getting the value of _x, not a
// reference to it (off course all this 
// new ref& syntax is confusing as you 
// don't need to dereference but I guess
// it's the cpp way.)
Brain& Human::getBrain(void) {
	return this->_brain;
}