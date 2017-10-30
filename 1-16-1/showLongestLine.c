#include <stdio.h>
#define MAXLEN 1000
int getLine(char line[]);
int copy(char from[], char to[]);
/* Print the longest line from the input */
int main() {
	int length, longestLength;
	char line[MAXLEN], longestLine[MAXLEN];
	longestLength = 0;
	/* Continue if the length of the next line is not EOF */
	while((length = getLine(line)) != EOF)
		/* If the length of this line exceeds the current
		longest line, then this line is now the longest */
		if(length > longestLength) {
			/* Store this line as the longest */
			copy(line, longestLine);
			/* Update the longest length*/
			longestLength = length;
		}
	/* Print the longest line when we have reached EOF */
	printf("\nLongest Line:\n%s\n", longestLine);
	return 0;
}
/* Place the next line from the input into a string */
/* Returns the length of the line - or EOF to signal as such */
int getLine(char line[]) {
	int c, i;
	/* As long as we haven't reached EOF and the next character is 
	not '\n', then assign this next character as the next element of
	line[] */
	for(i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF 
		&& c != '\n'; ++i)
		line[i] = c;
	/* If there were any characters, then append '\0' to line[] */
	if(i)
		line[i] = '\0';
	/* If there were no characters and EOF was reached, return it */
	else if(c == EOF)
		return EOF;
	/* Return the length of the line */
	return i;
}
/* Copy the contents of one string into another */
int copy(char from[], char to[]) {
	int i;
	/* Place each character from from[] into to[], stopping after
	the null terminator has been placed in to[] */
	for(i = 0; (to[i] = from[i]) != '\0'; ++i);
	return 0;
}
