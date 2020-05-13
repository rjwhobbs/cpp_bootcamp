#include <iostream>
#include <string>
using namespace std;

string f_one(void) {
	string test = "words";
	return test;
}

int main(void) {
	string test = f_one();
	cout << test << endl;
	return 0;
}