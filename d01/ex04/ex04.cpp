#include <iostream>
#include <string>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string& strRef = str;
	std::string* strPtr = &str;

	std::cout << "By ref: " << strRef << std::endl;
	std::cout << "By dereference from pointer: " << *strPtr << std::endl;

	return 0;
}