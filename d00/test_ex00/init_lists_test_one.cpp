#include <iostream>
#include <vector>
using namespace std;

class Test 
{
public:
	Test(int x, int y);
	~Test();

	void putXY(void) const;
	
private:
	int _x;
	int _y;
};

Test::Test(int x, int y) : _x(x), _y(y)
{
	cout << this->_x << ' ' << this->_y << endl;
}

Test::~Test(){}

void Test::putXY(void) const
{
		cout << this->_x << ' ' << this->_y << endl;
}

int main(void)
{
	vector<Test> test_v(5, Test(21, 43));
	test_v[0].putXY();
	test_v[4].putXY();
	return 0;
}