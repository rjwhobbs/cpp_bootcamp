#include <iostream>
#include <vector>
#include "Test.class.hpp"
using namespace std;

void f_two(void) {
	Test test;
	cout << Test::getNbInst() << " in f_two()" << endl;
	return ;
}

void f_one(void) {
	Test test;
	cout << Test::getNbInst() << " in f_one()" << endl;
	f_two();
	return ;
}

int main(void) {
	int arr[] = {12, 23, 34, 45};
	vector<Test::t> test(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	// cout << test[1].y << " main"<< endl;
	vector<Test::t>::iterator b = test.begin();
	vector<Test::t>::iterator e = test.end();

	while (b != e) {
		cout << b->getNbInst() << endl;
		b++;
	}

	return 0;
}