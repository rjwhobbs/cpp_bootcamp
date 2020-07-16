#include <fstream>	
#include <string>	
#include <iostream>	
#include <sstream>
#include "FragTrap.hpp"

// class Foo {
// 	public:
// 		Foo(int x);
// 		~Foo(void);

// 		int x;
// };

// Foo::Foo(int x) : x(x) {
// 	std::cout
// 		<< "Foo's con called, x is "
// 		<< this->x
// 		<< std::endl;
// }

// Foo::~Foo(void) {
// 	std::cout
// 		<< "Foo's des called"
// 		<< std::endl;
// }

// class Bar : public Foo {
// 	public:
// 		Bar(int y);
// 		~Bar(void);

// 		int y;
// };

// Bar::Bar(int y) : Foo(99), y(y) {
// 	std::cout
// 		<< "Bar's con called, x from Foo is "
// 		<< this->x
// 		<< " Y is "
// 		<< this->y
// 		<< std::endl;
// }

// Bar::~Bar(void) {
// 	std::cout
// 		<< "Bar's des called"
// 		<< std::endl;	
// }

int main(void) {
	FragTrap a("Mike");

	a.meleeAttack("Dog biscuit");
	a.rangedAtack("Cat biscuit");
	a.takeDamage(33);
	a.beRepaired(1);
	// Bar(5);	
	return 0;	
}