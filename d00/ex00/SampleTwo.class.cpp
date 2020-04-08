#include "SampleTwo.class.hpp"

SampleTwo::SampleTwo(int foo) {
	this->_foo = foo;
}

SampleTwo::~SampleTwo() {
}

int SampleTwo::getFoo(void) const {
	return this->_foo;
}

int SampleTwo::compare(SampleTwo* other) const {
	if (this->_foo < other->getFoo()) {
		return -1;
	} else if (this->_foo > other->getFoo()) {
		return 1;
	} else {
		return 0;
	}
}