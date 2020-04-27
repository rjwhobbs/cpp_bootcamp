#include <iostream>

int bar = 99;

int f(void) {
		return 9000;
}
// New scope
namespace Foo {
	int bar = 21;
	int f(void) {
		return 42;
	}
}
// :: = scope resolution opperator
int main(void) {
	printf("%d\n", Foo::bar); //21
	printf("%d\n", Foo::f()); //42
	printf("%d\n", ::bar); // refers to global scope
	printf("%d\n", ::f());
	printf("%d\n", bar); //99
	printf("%d\n", f());//9000
	return 0;
}