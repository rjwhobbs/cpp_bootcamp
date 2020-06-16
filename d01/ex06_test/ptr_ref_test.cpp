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

class StudentTwo {
	private:
		string _login;

	public:
		StudentTwo(string const& login) : _login(login) {}
		~StudentTwo(void) {}

		string& getLoginRef(void) {
			return this->_login;
		}

		string const& getLoginRefConst(void) const {
			return this->_login;
		}

		string* getLoginPtr(void) {
			return &(this->_login);
		}

		string const* getLoginPtrConst(void) const {
			return &(this->_login);
		}
};

int main(void) {
	string name = "Potato";
	StudentTwo stu = StudentTwo("Jack");

	cout << *(stu.getLoginPtrConst()) << endl; 
	*(stu.getLoginPtr()) = "The dude"; 
	cout << *(stu.getLoginPtrConst()) << endl; 
	stu.getLoginRef() = "The Chana"; 
	cout << *(stu.getLoginPtrConst()) << endl; 

	Student student(name);
	cout << student.getLogin() << endl;
	name = "Cheese";
	cout << student.getLogin() << endl;

	return 0;
}