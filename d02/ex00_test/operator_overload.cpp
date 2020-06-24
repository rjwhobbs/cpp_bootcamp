#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

class Interger {
	public:
		Interger(int const n);
		~Interger(void);

		int getValue(void) const;

		Interger& operator=(Interger const& rhs);
		Interger operator+(Interger const& rhs) const;

	private:
		int _n;
};

Interger::Interger(int const n) : _n(n) {
	std::cout << "Constructor " << n << std::endl;
}

Interger::~Interger(void) {
	std::cout << "Destructor " << this->_n << std::endl;
}

int Interger::getValue(void) const {
	return this->_n;
}

Interger& Interger::operator=(const Interger &rhs) {
	std::cout << "Assignation called from " 
		<< this->_n
		<< " to " 
		<< rhs.getValue() 
		<< std::endl;

	this->_n = rhs.getValue();
	return *this;
}

Interger Interger::operator+(const Interger &rhs) const {
	std::cout << "Addition called with "
		<< this->_n
		<< " and " 
		<< rhs.getValue()
		<< std::endl;

		return Interger(this->_n + rhs.getValue());
} 

std::ostream& operator<<(std::ostream& o, Interger const& rhs) {
	o << rhs.getValue();
	return o;
}

int main(void) {

	Interger x(1);
	Interger y(2);
	Interger z(3);

	// int e = 2;
	// int f = 3;
	// int g = 4;

	//Interger a = z.operator+(y); 
	// Interger a = z + y;
	Interger a = x.operator+(y.operator+(z)); 
	// Interger a = x + y + z;
	std::cout << a << std::endl;
	// int q = e + f + g;
	// std::cout << q << std::endl;

	// Interger c = a + x;
	// std::cout << c << std::endl;


	// std::cout << "x " << x << std::endl;
	// std::cout << "y " << y << std::endl;
	// std::cout << "z " << z << std::endl;

	// y = 99;
	// std::cout  << (z + 42) << std::endl;

	// std::cout << "y " << y << std::endl;

	return 0;
}