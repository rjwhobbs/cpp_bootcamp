#include <stdio.h>
#include <string.h>

void fn(char *str) {
	printf("In fn %p\n", str);
	*str++;
	printf("In fn after inc %p\n", str);
	*str = 'x';
}

int	main(void) {
	char *str = strdup("Hello");
	printf("before fn %p\n", str);
	fn(str);
	printf("after fn %p\n", str);
	printf("%s\n", str);

	return (0); 
}