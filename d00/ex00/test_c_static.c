#include <stdio.h>

int fx(void) {
	int static i;
	i += 1;

	return i;
}

int main(void) {

	int j = 0;

	while (j < 10) {
		printf("%d\n", fx());
		j++;
	}

	return 0;
}