#include <iostream>
#include <string>
#include <sstream>

class Brain {

	public:
		Brain(void);
		~Brain(void);

		std::string identify(void) const;

};

Brain::Brain(void) {
	return ;
}

Brain::~Brain(void) {
	return ;
}

std::string Brain::identify(void) const {
	std::stringstream addressStream;
	std::string address;

	addressStream << this;
	address = addressStream.str();

	return address;
}

class Human : public Brain {
	
	public:
		Human(void) {};
	 	~Human(void) {};

		Brain getBrain(void) {
			return this->brain;
		}

		Brain const brain;
};

int main(void) {
	Human human;
	Brain brain;
	std::cout << human.identify() << std::endl;
	std::cout << human.getBrain().identify() << std::endl;
}