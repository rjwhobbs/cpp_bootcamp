#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> int_v(5, 1);
	vector<int>::iterator b = int_v.begin();
	vector<int>::iterator e = int_v.end();

	while (b != e) {
		cout << *b << endl;
		b++;
	}
	return 0;
}