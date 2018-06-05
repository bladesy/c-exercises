#include <stdio.h>

#define MAXLEN 1000

int getLine(char line[]);
int copyLine(char from[], char to[]);

/* Print the longest line from the input. */
int main(void) {
	char line[MAXLEN], longestLine[MAXLEN];
	int length, longestLength;
	
	longestLength = 0;
	
	/* Continue if the next line has a valid length. */
	while((length = getLine(line)) != EOF)
		/* If the length of this line exceeds the current longest line,
		then this line is now the longest. */
		if(length > longestLength) {
			/* Store this line as the longest. */
			copy(line, longestLine);
			/* Update the longest length. */
			longestLength = length;
		}
	
	/* Print the longest line when we have reached EOF. */
	printf("\nLongest Line:\n%s\n", longestLine);
	
	return 0;
}

/* Place the next line from the input into a string. Returns the length
of the line - or EOF to signal as such. */
int getLine(char line[]) {
	int c, i;
	
	i = 0;
	
	/* As long as we haven't reached EOF and the next character is not
	'\n', then assign this next character as the next element of
	line[]. */
	while(i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	
	/* If there were any characters, then append '\0' to line[]. */
	if(i)
		line[i] = '\0';
	/* If there were no characters and EOF was reached, return it. */
	else if(c == EOF)
		return EOF;
	
	/* Return the length of the line. */
	return i;
}

/* Copy the contents of from into to. */
int copyLine(char from[], char to[]) {
	int i;
	
	/* Place each character from from[] into to[], stopping after the
	null terminator has been placed in to[]. */
	for(i = 0; (to[i] = from[i]) != '\0'; ++i);
	
	return 0;
}
