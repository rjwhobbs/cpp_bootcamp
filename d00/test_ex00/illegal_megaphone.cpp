#include <iostream>
#include <algorithm> // Illegal, uses <algorithm>

void toupper_fn(char &c) { // So it looks like cpp can decide to pass by ref or val. See for_each man cpp
	c = toupper(c);
}

int main(int ac, char *av[]) {

	int i = 1;

	if (ac == 1) {
		return (0);
	}

	std::string args;
	while (i < ac) {
		if (i < ac - 1) {
			args += av[i];
			args.push_back(' ');
		} else {
			args += av[i];
		}
		i++;
	}
	// printf("%ld\n", it);

	std::for_each(args.begin(), args.end(), toupper_fn);
	std::cout << args << std::endl;

	return (0);
}