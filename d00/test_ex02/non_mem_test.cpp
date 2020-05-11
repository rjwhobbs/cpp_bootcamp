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
	cout << Test::getNbInst() << " main" << endl;
	f_one();
	cout << Test::getNbInst() << " After f_one()" << endl;
	// vector<Test::t> test(3, 77);
	// cout << test[3].y << endl;

	return 0;
}