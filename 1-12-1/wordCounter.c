#include <stdio.h>
#define IN 1
#define OUT 0
/* Counts the number of words in the input */
int main() {
	int c, words, state;
	/* Variable initialisations */
	words = 0;
	state = OUT;
	while((c = getchar()) != EOF)
		/* If we have reached whitespace, then we are outside
		a word */
		if(c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		/* If we are not in whitespace after just having been in
		it, then we have reached a new word - setting our state
		to IN means that the next time a word will be counted
		will be after entering and exiting whitespace again */
		else if(state == OUT) {
			++words;
			state = IN;
		}
	/* Print the word count */
	printf("Words: %3d\n", words);
	return 0;
}
