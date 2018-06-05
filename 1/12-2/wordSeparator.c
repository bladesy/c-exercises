#include <stdio.h>

#define IN 0
#define OUT 1

/* Prints the input one word per line. */
int main(void) {
	char c;
	int state;
	
	state = OUT;
	
	while((c = getchar()) != EOF) {
		/* If we have reached whitespace, then we are outside a word. */
		if(c == ' ' || c == '\t' || c == '\n') {
			/* Only give a new line if there was a word previously. */
			if(state == IN) {
				putchar('\n');
				state = OUT;
			}
		}
		/* If we are not in whitespace after just having been in
		whitespace, then we have reached a new word. */
		else if(state == OUT)
			state = IN;
		
		/* Print the character if it is inside a word. */
		if(state == IN)
			putchar(c);
	}
	
	return 0;
}
