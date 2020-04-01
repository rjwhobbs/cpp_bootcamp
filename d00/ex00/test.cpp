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

class Qux {
	public:
	Qux() : _foo("Make this foo"), _bar("And this bar") {}

	private:
	std::string _foo;
	std::string _bar;
};

int main(void) {
	Bar bar;
	Qux qux;

	return (0);
}