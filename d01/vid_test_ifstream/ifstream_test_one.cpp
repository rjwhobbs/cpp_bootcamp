#include <fstream>
#include <iostream>

using namespace std;

int	main(void)
{
	ifstream ifs("./numbers");
	int i;
	int j;
	ifs >> i >> j;

	// This seperates by white space
	// so streams do some kind of type conversions? 
	// ie 9877sdf89d becomes 9877
	cout << i << '\n' << j << endl; // 345345 , 9877
	ifs.close();
	return 0;
}