#include <stdio.h>

#define MAXLEN 1000
#define MAXCOL 72

/* Fold input lines into multiple lines, such that no line exceeds
MAXCOL characters. */
int main(void) {
	int c, count;
	
	count = 0;
	
	while((c = getchar()) != EOF) {
		putchar(c);
		++count;
		
		if(c == '\n')
			count = 0;
		
		if(count == MAXCOL) {
			putchar('\n');
			count = 0;
		}
	}
	
	return 0;
}
