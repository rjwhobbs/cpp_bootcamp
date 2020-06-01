#include <sstream>
#include <iostream>

using namespace std;

int main(void)
{
	stringstream ss;

	int foo, bar;

	//Once again the white space seperation
	ss << 12 << '\t' << 78;
	ss >> foo >> bar;

	cout << foo << endl;
	cout << bar << endl;

	return 0;
}