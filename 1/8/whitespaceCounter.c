#include <stdio.h>

/* Count the blanks, tabs and new lines in the input text. */
int main(void) {
	char c;
	int blanks, tabs, newLines;
	
	blanks = tabs = newLines = 0;
	
	/* Give c the next character, unless the next character is EOF. */
	while((c = getchar()) != EOF) {
		/* Consider values of c, and increment variables as such. */
		switch(c) {
			case ' ':
				blanks++;
				break;
			case '\t':
				tabs++;
				break;
			case '\n':
				newLines++;
				break;
		}
	}
	
	/* Print formatted variable values. */
	printf("\nBlanks:%3d\nTabs:%3d\nNew Lines:%3d\n", blanks, tabs,
		newLines);
	
	return 0;
}
