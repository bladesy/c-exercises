#include <stdio.h>

#define MAXLEN 1000

int getLine(char line[]);

/* Print the length of each line. */
int main(void) {
	char line[MAXLEN];
	int length;

	/* Continue if the next line has a valid length. */
	while((length = getLine(line)) != EOF)
		/* Print the length of the line. */
		printf("Length: %d\n", length);	
	
	return 0;
}

/* Place the next line from the input into a string. Returns the length
of the line - or EOF to signal as such. */
int getLine(char line[]) {
	int c, i;
	
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
