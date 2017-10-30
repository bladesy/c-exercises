#include <stdio.h>
#define MAXLEN 1000
int getLine(char line[]);
int copy(char from[], char to[]);
/* Print the length of each line */
int main() {
	int length;
	char line[MAXLEN];
	/* Continue if the length of the next line is not EOF */
	while((length = getLine(line)) != EOF)
		/* Print the length of the line */
		printf("Length: %d\n", length);	
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
