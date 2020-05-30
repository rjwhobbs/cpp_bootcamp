#include <iostream>
#include <vector>
using namespace std;

class TestOne 
{
public:
	TestOne(int x, int y);
	~TestOne();

	void putXY(void) const;
	
private:
	int _x;
	int _y;
};

TestOne::TestOne(int x, int y) : _x(x), _y(y)
{
	cout << this->_x << ' ' << this->_y << endl;
	cout << "From TestOne constructor" << endl;
}

TestOne::~TestOne(){}

void TestOne::putXY(void) const
{
		cout << this->_x << ' ' << this->_y << endl;
}

/* ------------------------------------------------ */

class TestTwo: public TestOne
{
public:
	TestTwo();
	
};

TestTwo::TestTwo(void) : TestOne(65, 54)
{
		cout << "From TestTwo constructor" << endl;
}

int main(void)
{
	// vector<TestOne> test_v(5, TestOne(21, 43));
	// test_v[0].putXY();
	// test_v[4].putXY();
	TestTwo t;
	t.putXY();
	return 0;
}