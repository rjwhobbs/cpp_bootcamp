#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int const 		dep[]	= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const 	dep_size( sizeof(dep) / sizeof(int) );
	vector<int> 	int_v(dep, dep + dep_size); // with this constructor it takes pointers to the begining and end of the array.
	vector<int>::iterator b = int_v.begin();
	vector<int>::iterator e = int_v.end();

	cout << (dep_size) << endl;
	cout << (dep) << endl;
	// while (b != e) {
	// 	cout << *b << endl;
	// 	b++;
	// }
	return 0;
}