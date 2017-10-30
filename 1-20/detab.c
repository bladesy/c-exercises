#include <stdio.h>
/* Constants */
/* Max number of blanks that a tab can consist of */
#define TABSTOP 8
/* Function Prototypes */
/* Replaces tabs in the input with the equivalent number of blanks */
int main(void) {
	int c, charNum, charPos;
	charNum = 0;
	while((c = getchar()) != EOF)
		/* If the character is a tab, replace it with blanks */
		if(c == '\t')
			/* Fill the distance in characters to the next
			TABSTOP with blanks - ensure that each blank is
			also considered as a character and thus 
			incremented */
			for(charPos = charNum % TABSTOP;
				charPos < TABSTOP; ++charPos, ++charNum)
				putchar(' ');
		/* If the character is not a tab, print it and increment
		the total character count */
		else {
			putchar(c);
			++charNum;
		}	
	return 0;
}
