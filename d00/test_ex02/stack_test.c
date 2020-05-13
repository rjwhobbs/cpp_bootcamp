#include <stdio.h>
#include <string.h>

//So this isn't possible, well recommended in c but in cpp one can do this with strings, why is that?
//test[] = warning: address of stack memory associated with local variable 'test' returned [-Wreturn-stack-address]
//But when I use string literals it works in c? and no compiler warning?
char* f_one(void) {
	char *test = "words";
	return test;
}

int main(void) {
	char *test = f_one();
	printf("%s\n", test);
	int i = 0;
	while (*test) {
		putchar(*test++);
	}
	return 0;
}