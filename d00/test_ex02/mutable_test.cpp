#include <iostream>
using namespace std;

class Test {
	public: 
	static int x;
	mutable int y;	
	void f(void) const;
};

// why can f() change the value of x here? even though its const
int Test::x = 42;
void Test::f(void) const {
	this->x += 1;
	this->y = 9000;
	cout << this->x << endl;
	cout << this->y << endl;
}

int main(void) {
	Test t;
	t.f();

	return 0;
}