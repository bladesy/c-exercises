#include <stdio.h>
/* Constant Definitions */
#define TABSTOP 8
/* Replace consecutive blanks with tab where possible */
int main(void) {
	int c, charNum, blankNum;
	blankNum = charNum = 0;
	while((c = getchar()) != EOF)
		/* If c is blank, increment counters and check if a
		tabstop has been reached */
		if(c == ' ') {
			++charNum;
			++blankNum;
			/* If a tabstop has been reached, place a tab
			and discard the blanks it replaced */
			if(!(charNum % TABSTOP)) {
				putchar('\t');
				blankNum = 0;
			}
		}
		/* If c is not a blank, print pending blanks before
		printing c, clearing the counters if the line ends */
		else {
			/* If there are blanks, print them */
			while(blankNum) {
				putchar(' ');
				--blankNum;
			}
			putchar(c);
			/* The counters are only relative to the current
			line, so they must be cleared in preparation for
			the next line */
			if(c == '\n')
				blankNum = charNum = 0;
			else
				++charNum;
		}
	return 0;
}	
