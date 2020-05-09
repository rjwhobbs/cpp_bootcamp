#include <iostream>
#include "Temp.class.hpp"
//#include "Temp.class.cpp" // This is probably not allowed by 42
using namespace std;

int main(void) {
	Temp<int> temp(1, 2);
	// Temp temp;
	cout << temp.a << endl;
	return 0;
}