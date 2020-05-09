#include <iostream>
#include <string>
using namespace std;

template<class T> 
T GetMax(T a, T b) {
	T res;
	res = a > b ? a : b;
	return res;
}

// T GetMaxTwo(T a, T b) { // errs
// 	T res;
// 	res = a > b ? a : b;
// 	return res;
// }

template<class T, class U>
T GetMin(T a, U b) {
	return (a < b)? a: b;
}

int main(void) {
	int i = 9000;
	long l = 9999;
	string str_one = "a";
	string str_two = "B";
	cout << GetMax<int>(42, 21) << endl;
	cout << GetMax(42, 21) << endl; // implicit
	// cout << GetMax(42, str_one) << endl; // errs
	cout << GetMax<string>(str_one, str_two) << endl;
	cout << GetMin(i, l) << endl; // implicit;
	return 0;
}