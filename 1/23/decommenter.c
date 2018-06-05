#include <stdio.h>

#define MAXLEN 1000

#define IN 0
#define OUT 1

int getLine(char line[]);
int copyLine(char from[], char to[]);
int decommentLine(char line[]);

int state;

/* Remove comments from C source files. */
int main(void) {
	char line[MAXLEN];
	int length;
	
	state = OUT;
	
	while((length = getLine(line)) != EOF)
		if(length == 0)
			putchar('\n');
		else if(decommentLine(line) > 0)
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

/* Copy the contents of from into to, returning the length of to. */
int copyLine(char from[], char to[]) {
	int i;
	
	/* Place each character from from[] into to[], stopping after the
	null terminator has been placed in to[]. */
	for(i = 0; (to[i] = from[i]) != '\0'; ++i);
	
	return i;
}

/* Remove comments from line, returning the new length of the line. */
int decommentLine(char line[]) {
	char tempLine[MAXLEN];
	int i, j;
	
	for(i = 0, j = 0; line[i]; ++i) {
		if(line[i] == '/' && line[i + 1] == '*')
			state = IN;
		
		if(state == OUT)
			tempLine[j++] = line[i];
		
		if(line[i] == '*' && line[i + 1] == '/') {
			state = OUT;
			++i;
		}
	}
	
	tempLine[j] = '\0';
	copyLine(tempLine, line);
	
	return j;
}
