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
	cout << i << '\n' << j << endl; // 345345 , 987789
	ifs.close();
	return 0;
}