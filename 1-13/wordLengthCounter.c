#include <stdio.h>
#define IN 1
#define OUT 0
/* Counts and presents the number of words of varying word length from
within the input */
int main() {
	/* Analyse input */
	/* Variable declarations */
	/* [0] is taken as word length of 1, and so forth */
	int c, i, j, chars, words[9];
	/* Variable and array initialisations */
	chars = 0;
	for(i = 0; i < 9; ++i)
		words[i] = 0;
	/* Taking each character as c */
	while((c = getchar()) != EOF)
		/* When whitespace is reached, increment the word count 
		based on the previous word if and only if there was one,
		and reset the character count */
		if(c == ' ' || c == '\t' || c == '\n') {
			if(chars)
				/* Must account for word length 1 being
				stored as element 0 */
				++words[chars - 1];
			chars = 0;
		}
		/* If we haven't reached whitespace, then the character
		count of the word should be incremented */
		else
			++chars;
	/* Print histogram */
	/* For each of the chosen word lengths, print out a bar */
	for(i = 0; i < 9; ++i) {
		/* If the element is empty, move onto the next */
		if(!words[i])
			continue;
		printf("There are %3d words of length %d: ", 
			words[i], i + 1);
		/* For every word of the current word length, print out
		a hash */
		for(j = 0; j < words[i]; ++j)
			putchar('#');
		putchar('\n');
	}		
	return 0;
}
