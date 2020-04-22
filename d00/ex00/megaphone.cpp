#include <iostream>
#include <algorithm>

void test_func(char& c) {
	c = 'x';
}

int main(int ac, char* av[]) {
	if (ac == 1) {
		return (0);
	}

	std::string test = av[1];
	// test += av[2];

	// std::for_each(test.begin(), test.end(), test_func);
	// std::cout << test;

	std::string str = "zzz";
	test_func(str[0]);

	std::cout << str << std::endl;

	return (0);
}