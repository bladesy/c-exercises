#include<stdio.h>

#define IN 0
#define OUT 1

/* Remove comments from C code - does not account for the lines comments
create. */
int main(void) {
	char c, d;
	int state;
	
	state = OUT;
	
	while((c = getchar()) != EOF) {
		if(c == '/') {
			if((d = getchar()) == '*')
				state = IN;
			else {
				putchar(c);
				putchar(d);
			}
		}
		else if(state == OUT)
			putchar(c);
		else if(c == '*')
			if((d = getchar()) == '/')
				state = OUT;
	}
	
	return 0;
}
