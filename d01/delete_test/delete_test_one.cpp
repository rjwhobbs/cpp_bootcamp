#include <iostream>
using namespace std;

class Test
{
public:
	Test();
	~Test();

	void saySomething(void) const;
};

Test::Test(void)
{
	cout << "Test created" << endl;
}

void Test::saySomething(void) const
{
	cout << "Something" << endl;
}

Test::~Test(void)
{
	cout << "Test deleted" << endl;
}

int main(void)
{
	Test* tests = new Test[10];

	tests->saySomething();
	tests++;
	tests->saySomething();
	delete[] tests;
	// a.out(56914,0x10b68adc0) malloc: *** error for object 0x7f9e1d4058b1: pointer being 
	// freed 
	// was not allocated
	// a.out(56914,0x10b68adc0) malloc: *** set a breakpoint in malloc_error_break to debug
	// Abort trap: 6
	return 0;
}