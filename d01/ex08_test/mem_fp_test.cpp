#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Test {
	public:
		Test(int x, int y) : _x(x), _y(y) {}
		~Test(void) {}

		void showValue(void) {
			typedef int (Test::*APtr)();
			APtr gptr[] = {&Test::_getX, &Test::_getY};

			cout << (this->*gptr[0])() << endl;
		}

	private:
		int _x;
		int _y;
		int _getX(void) {
			return this->_x;
		}	     
		int _getY(void) {
			return this->_y;
		}	     
};

int main(void) {
	Test t(55, 44);
	t.showValue();
}