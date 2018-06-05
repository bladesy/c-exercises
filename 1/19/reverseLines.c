#include <stdio.h>

#define MAXLEN 1000

int getLine(char line[]);
int reverseLine(char line[], int length);

/* Reverse input lines. */
int main(void) {
	char line[MAXLEN];
	int length;
	
	/* Get the length of each line, until EOF has been reached. */
	while((length = getLine(line)) != EOF) {
		/* Reverse the current line then print. */
		reverseLine(line, length);
		printf("%s\n", line);
	}
	
	return 0;
}

/* Place the next line from the input into line. Returns the length of
the line - or EOF to signal as such. */
int getLine(char line[]) {
	int c, i;
	
	i = 0;
	
	/* Get each character until EOF or \n are reached. */
	while((c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	
	/* Null terminate. */
	line[i] = '\0';
	
	/* If there are no characters on the line where EOF is reached, then
	return EOF as a signal. */
	if(c == EOF)
		return EOF;
	
	/* If there are characters, then the line length is returned. */
	return i;
}

/* Reverse the character order of line of length. */
int reverseLine(char line[], int length) {
	int c, i, lastPos;
	
	/* A line of length less than 1 is not valid. */
	if(length < 1)
		return -1;
	
	/* Swap the first half of the string with the last half - the
	condition check is using the truncation of integers to round
	down in the case of an odd number, where the middle number will
	stay the same. */
	for(i = 0, lastPos = length - 1; i <= lastPos / 2; ++i) {
		c = line[i];
		line[i] = line[lastPos - i];
		line[lastPos - i] = c;
	}
	
	return 0;
}
