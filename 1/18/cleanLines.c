#include <stdio.h>

#define MAXLEN 1000

int getLine(char line[]);
int cleanLine(char line[], int length);

/* Remove trailing blanks and tabs from each line of input, deleting
entirely blank lines. */
int main(void) {
	char line[MAXLEN];
	int length, cleanLength;
	
	/* Get the length of each line, until EOF has been reached. */
	while((length = getLine(line)) != EOF)
		/* Print line if its length isn't 0 after cleaning. */
		if((cleanLength = cleanLine(line, length)))
			printf("%s\n", line);
	
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

/* Remove trailing blanks and tabs from line of length. */
int cleanLine(char line[], int length) {
	int i;
	
	i = length;
	
	/* Count down from the last character of line (before the null
	terminator), changing the trailing blanks and tabs to the null
	terminator, until a different character is encountered. */
	while(i-- > 0)
		if(line[i] == ' ' || line[i] == '\t')
			line[i] = '\0';
		else
			break;
	
	/* Compensate i for the final null terminator. */
	return ++i;
}
