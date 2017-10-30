#include <stdio.h>
/* Copy input to output, trimming consecutive blanks into only one */
int main() {
	int c;
	/* Let c be the next character as long as it isn't EOF */
	while((c = getchar()) != EOF) {
		/* Print character regardless of value */
		putchar(c);
		/* As long as c is blank, it must be replaced with the
		next character, to avoid consecutive blanks */
		while(c == ' ') {
			c = getchar();
			/* If c isn't a blank anymore, we have 
			eliminated the consecutive blanks, so we can 
			print it and start the cycle again */
			if(c != ' ')
				putchar(c);
		}
	}
	return 0;
}
