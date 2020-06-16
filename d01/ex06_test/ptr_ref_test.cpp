#include <iostream>
#include <string>

using namespace std;

class Student {
	public:
		Student(string& login) : _login(&login) {}
		~Student(void) {}

		string getLogin(void) const {
			return *(this->_login);
		}

	private:
		string* _login;
};

int main(void) {
	string name = "Potato";

	Student student(name);
	cout << student.getLogin() << endl;
	name = "Cheese";
	cout << student.getLogin() << endl;

	return 0;
}