#include <stdio.h>
#define MAXLEN 1000
int getLine(char line[]);
/* Print all input lines longer than 80 characters */
int main() {
	int length;
	char line[MAXLEN];
	/* Get the length of each line, until EOF has been reached */
	while((length = getLine(line)) != EOF)
		/* Print the line if its length is greater than 80 */
		if(length > 80)
			printf("%s\n", line);
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
