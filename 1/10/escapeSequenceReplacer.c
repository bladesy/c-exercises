#include <stdio.h>

/* Replaces tabs, backspaces and backslashes with escape sequences. */
int main(void) {
	char c;
	
	while((c = getchar()) != EOF)
		/* Test the value of c and print out the corresponding string
		format. */
		switch(c) {
			case '\t':
				printf("\\t");
				break;
			case '\b':
				printf("\\b");
				break;
			case '\\':
				printf("\\\\");
				break;
			/* Print c normally if it doesn't match the above cases. */
			default:
				putchar(c);
				break;
		}
	
	return 0;
}
