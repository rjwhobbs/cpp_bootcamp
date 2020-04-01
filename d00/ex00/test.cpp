#include <iostream>

class Foo {
	public:
	Foo() {
		std::cout << "foo's constructor default" << std::endl;
	}
	public:
	Foo(int x) {
		std::cout << "foo's constructor " << x << std::endl;
	}
};

class Bar : public Foo {
	public:
	Bar() : Foo(10) {
		std::cout << "Bar's constructor" << std::endl;
	}
};

int main(void) {
	Bar bar;
}