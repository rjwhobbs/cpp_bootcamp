#include <fstream>
#include <iostream>

using namespace std;

int	main(void)
{
	ifstream ifs("./numbers");
	int i;
	int j;
	ifs >> i >> j;

	cout << i << '\n' << j << endl; // 345345 , 987789
	return 0;
}