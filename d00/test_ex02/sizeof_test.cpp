#include <iostream>
using namespace std;

int main(void) {
	int	const	amounts[]	= { 42, 54, 957, 432, 1234, 0, 754 };
	size_t const amounts_size = sizeof(amounts) / sizeof(int);
	cout << amounts_size << endl;
	cout << sizeof(amounts) << endl;
	return 0;
}