#include <stdio.h>
#define MAXLEN 1000
int getLine(char line[]);
int reverseLine(char line[], int length);
/* Reverse input lines */
int main() {
	int length;
	char line[MAXLEN];
	/* Get the length of each line, until EOF has been reached */
	while((length = getLine(line)) != EOF) {
		reverseLine(line, length);
		printf("(Reverse) %s\n", line);
	}
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
int reverseLine(char line[], int length) {
	int c, i;
	/* Swap the first half of the string with the last half - the
	condition check is using the truncation of integers to round
	down in the case of an odd number, where the middle number will
	stay the same */
	/* Length is initially decremented to exclude null terminator */
	for(i = 0, --length; i <= length / 2; ++i) {
		c = line[i];
		line[i] = line[length - i];
		line[length - i] = c;
	}
	return 0;
}
