#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	stringstream strs;
	string s1;
	string s2;
	ifstream ifs("test.txt");
	ifs.seekg(5);

	ifs >> s1 >> s2;
	cout << s1 << s2 << endl;
	// strs << ifs.rdbuf();
	// cout << strs.str();

	ifs.close();
	return 0;
}