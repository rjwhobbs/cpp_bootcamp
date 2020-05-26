#include <iostream>
using namespace std;

class Test {
	public: 
	static int x;	
	void f(void) const;
};

// why can f() change the value of x here? even though its const
int Test::x = 42;
void Test::f(void) const {
	this->x += 1;
	cout << this->x << endl;
}

int main(void) {
	Test t;
	t.f();

	return 0;
}