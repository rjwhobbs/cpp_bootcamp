#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sys/stat.h>

// So while get() doesn't encounter a delimiter
	// cout carries on buffering it's stream,
	// once get() encounters a delimiter does it
	// release cout?
	// Seems like there are too things going on,
	// The while loop and std::cin.get() retruning a
	// a value other than null?


	// I thought get ignores the newline char?
	// if (c == '\n') {
	// 		std::cout << "WAAT";
	// 	}

void checkAccess(char *file) {
	std::string error;
	struct stat checkFile; 


	if (access(file, F_OK)) {
		error = "ft_cat: ";
		error += file;
		error += ": No such file or directory"; 
		std::cout << error << std::endl;
		return ;
	}

	if (access(file, R_OK)) {
		error = "ft_cat: ";
		error += file;
		error += ": Permission denied"; 
		std::cout << error << std::endl;
		return ;
	}

	lstat(file, &checkFile);

	if (checkFile.st_mode & S_IFDIR) {
		error = "ft_cat: ";
		error += file;
		error += ": Is a directory";
		std::cout << error << std::endl;
		return ;
	}

}

int main(int ac, char* av[]) {

	char c;
	std::ifstream ifs;

	if (ac == 1) {
		while (std::cin.get(c)) {
		std::cout << c;
		};
	}

	int i = 1;
	while (i < ac) {
		ifs.open(av[i]);

		while (ifs.get(c)) {
			std::cout << c;
		}

		checkAccess(av[i]);

		if (ifs.bad()) {
			ifs.close();
			std::cout << "i/o operation failure" << std::endl;
			return EXIT_FAILURE;
		}

		ifs.close();
		i++;
	}

	return 0;
}