#include <stdio.h>

int	main(void) {
	char c = 'x';
	char *pC;

	pC = &c;
	*pC = 'z';

	printf("%c\n", c);

	return (0); 
}