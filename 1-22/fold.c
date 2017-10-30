#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 10
#define MAXLEN 1000
#define MAXCOL 80

int getLine(char line[]);
int foldLine(char line[], char *lines[]);
int testLine(char line[], char **lines);

/* Fold input lines into multiple lines with length below the specified
character column */
int main(void) {
	int linesNum;
	char c, line[MAXLEN], *linePointer, **lines;
	
	/*
	while((linesNum = foldLine(line, (char **) lines)) != EOF)
		if(linesNum)
			printf("%s\n", line);
		while(linesNum)
			printf("%s\n", lines[--linesNum]);
	*/
	
	linePointer = line;
	while((c = getchar()) != '\n' && c != EOF)
		*(linePointer++) = c;
	testLine(line, lines);

	return 0;
}

/* Fill the given array with the next line from the standard input */
/* Return the line length */
int getLine(char line[]) {
	int length;
	char c, *linePointer;
	/* Storing the initial pointer to line allows us to use pointer
	arithmetic to find the length of the line */
	linePointer = line;
	while((c = getchar()) != '\n' && c != EOF)
		*(line++) = c;
	/* Null terminate the line, to avoid printf reading garbage
	values along with the rest of the characters */
	*line = '\0';
	length = line - linePointer;
	/* If there is no next line, then return that we have arrived at
	the end of the file */
	if(length == 0 && c == EOF)
		return EOF;
	return length;
}

int foldLine(char line[], char *lines[]) {
	int length, linesNum, startPos, endPos, i, j, k;
	char c, cPrev, **linesPointer;
	
	length = getLine(line);
	if(length == EOF)
		return EOF;
	
	linesNum = length / 80;
	if(length % 80)
		linesNum += 1;

	linesPointer = lines;

	while((lines - linesPointer) < linesNum) {
		i = length;
		while((c = line[i--]) == '\t' || c == ' ');
		endPos = ++i;

		if((j = endPos - MAXCOL) < 0)
			j = 0;

		while(c = line[j++])
			if((c != '\t' && c != ' ') 
				&& ((cPrev = line[j-2]) == '\t' 
				|| cPrev == ' '))
				startPos = --j;
		
		for(k = startPos; k < endPos; ++k)
			*((*lines)++) = line[k];
		**lines = '\0';

		length = startPos;
		++lines;
	}

	return linesNum;
}

int testLine(char line[], char **lines) {
	*lines = (char *) malloc(MAXLEN);
	while(line)
		*((*lines)++) = *(line++);
	return 0;
}
