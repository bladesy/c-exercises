#include <stdio.h>

#define MAXWORDLEN 9

/* Counts and presents the number of words of varying word length from
within the input. */
int main(void) {
	/* words[0] is taken as word length of 1, and so forth. */
	int c, i, j, chars, words[MAXWORDLEN];
	
	/* Variable and array initialisation. */
	chars = 0;
	for(i = 0; i < MAXWORDLEN; ++i)
		words[i] = 0;
	
	/* Taking each character in the input as c. */
	while((c = getchar()) != EOF)
		/* When whitespace is reached, increment the word count based on
		the previous word if and only if there was one, and reset the
		character count. */
		if(c == ' ' || c == '\t' || c == '\n') {
			if(chars)
				/* Must account for word length 1 being stored as
				element 0. */
				++words[chars - 1];
			chars = 0;
		}
		/* If we haven't reached whitespace, then the character count of
		the word should be incremented. */
		else
			++chars;
	
	/* Print histogram - for each of the chosen word lengths, print out
	a bar. */
	for(i = 0; i < MAXWORDLEN ++i) {
		/* If the element is empty, move onto the next. */
		if(!words[i])
			continue;
		
		printf("There are %3d words of length %d: ", words[i], i + 1);
		
		/* For every word of the current word length, print out a
		hash. */
		for(j = 0; j < words[i]; ++j)
			putchar('#');
		putchar('\n');
	}		
	
	return 0;
}
