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
			int (Test::*getXPtr)();
			getXPtr = &Test::_getX;

			cout << (this->*getXPtr)() << endl;
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