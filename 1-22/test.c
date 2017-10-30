#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *a, *b;
	a = (char *) malloc(5);
	*a = 'a';
	b = a;
	*b = 'n';
	if(a == b)
		printf("true\n");
	a = "this";
	if(a != b)
		printf("false\n");
	b = a;
	if(a == b)
		printf("true\n");
	*b = 'n';
	printf("%c\n", *b);
	return 0;
}
