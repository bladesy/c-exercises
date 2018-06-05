#include <stdio.h>
#define MAXLEN 1000
#define MAXLINES
#define MAXCOL 80

int getLine(char *line);
int foldLine(char *line, char *shortLine);

/* Separate lines into multiple, if they exceed a certain length */
int main(void) {
	char line[MAXLEN], *shortLines[MAXLINES];
	while(getLine(line)) {
		foldLine(line, shortLines);
		while(shortLines++)
			printf("%s\n", *shortLines);
	}
	return 0;
}

/* Fill the provided string with the next line from the input */
/* Returns the line length */
int getLine(char *line) {
	char c, *cp;
	cp = line;
	while((c = getchar()) != '\n' && c != EOF)
		*(cp++) = c;
	*cp = '\0';
	return cp - line;
}

/* Turns the line string into multiple lines, all just below the max
string length, and fills a string array up with these lines */
/* Returns the number of lines produced */
int foldLine(char *line, char **shortLines) {
	char shortLine[MAXCOL + 1], *lineStart, *lineEnd;
	lineStart = line;
	lineEnd = line + MAXCOL;
	if(isspace(*lineEnd) && isspace(*(lineEnd - 1))) {
		while(lineEnd - lineStart)
			**(shortLines++) = *(linestart++);
	}
	else {
		while(isspace(*(--lineEnd)));
	}

}
