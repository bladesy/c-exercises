#include <stdio.h>
#define MAXLEN 1000
int getLine(char line[]);
int cleanLine(char line[], int length);
/* Remove trailing blanks and tabs from each line of input, deleting
entirely blank lines */
int main() {
	int length, cleanLength;
	char line[MAXLEN];
	/* Get the length of each line, until EOF has been reached */
	while((length = getLine(line)) != EOF)
		/* Print line if its length isn't 0 after cleaning,
		provided that cleaning actually alters the line */
		if((cleanLength = cleanLine(line, length)) 
			&& cleanLength != length)
			printf("(Clean)%s\n", line);
	return 0;
}
int getLine(char line[]) {
	int c, i;
	/* Get each character until EOF or \n are reached */
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	/* If there are characters, then null terminate */
	if(i)
		line[i] = '\0';
	/* If there are no characters on the line where EOF is reached,
	then return EOF as a signal */
	else if(c == EOF)
		return EOF;
	/* If there are characters, then the line length is returned */
	return i;
}
int cleanLine(char line[], int length) {
	int i;
	i = length;
	/* Count down from the last character of line (before the null
	terminator), changing the trailing blanks and tabs to the null
	terminator, until a different character is encountered */
	while(i-- >= 0)
		if(line[i] == ' ' || line[i] == '\t')
			line[i] = '\0';
		else
			break;
	/* Compensate i for the null terminator */
	return ++i;
}
