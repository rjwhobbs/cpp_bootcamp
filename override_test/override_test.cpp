#include <iostream>
using namespace std;

class Foo {

	public :

	virtual void f(void) {
		cout << "Func f()" << endl;
	}

};

class Bar : public Foo {

	public :

	void f(void) override {
		cout << "Overriden Func f()" << endl;
	}

};

int main(void) {
	Foo foo;
	Bar bar;

	foo.f();
	bar.f();

	return 0;
}