#include <stdio.h>

#define MAXCHARLEN 72
#define MAXLINELEN 1000

int getLine(char line[]);

/* Print all input lines longer than MAXCHARLEN characters. */
int main(void) {
	char line[MAXLINELEN];
	int length;

	/* Get the length of each line, until EOF has been reached. */
	while((length = getLine(line)) != EOF)
		/* Print the line if its length is greater than MAXCHARLEN. */
		if(length > MAXCHARLEN)
			printf("%s\n", line);
	
	return 0;
}

/* Place the next line from the input into line. Returns the length of
the line - or EOF to signal as such. */
int getLine(char line[]) {
	int c, i;
	
	/* Get each character until EOF or \n are reached. */
	while((c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	
	/* If there are characters, then null terminate. */
	if(i)
		line[i] = '\0';
	/* If there are no characters on the line where EOF is reached,then
	return EOF as a signal. */
	else if(c == EOF)
		return EOF;
	
	/* If there are characters, then the line length is returned. */
	return i;
}
