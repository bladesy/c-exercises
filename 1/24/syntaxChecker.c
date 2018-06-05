#include <stdio.h>

#define MAXLEN 1000

typedef enum enclosure { PARENTHESIS, BRACKET, BRACE } Enclosure;
typedef enum readState { IN_COMMENT, IN_S_QUOTE, IN_D_QUOTE, OUT }
	ReadState;

int getLine(char line[]);
int enclosureCheck(char line[], Enclosure enclosure);

/* If parCount ever goes below 0, then there is a leading closing
parenthesis. If parCount goes above 0, then there are currently
unmatched opening parentheses. If parCount is 0 by the time EOF is
reached, then all parentheses have been matched. */
int parCount;

/* Similar to parCount, but for brackets. */
int bracketCount;

/* Similar to parCount, but for braces. */
int braceCount;

/* Determines whether enclosures matter to the syntax, by keeping track
of whether we are reading a comment or a type of quote. */
ReadState readState;

/* Check for unbalanced parentheses, brackets, and braces in C source
files. */
int main(void) {
	char line[MAXLEN];
	
	parCount = 0;
	bracketCount = 0;
	braceCount = 0;
	readState = OUT;
	
	while(getLine(line) != EOF) {
		if(parCount != -1)
			enclosureCheck(line, PARENTHESIS);
		if(bracketCount != -1)
			enclosureCheck(line, BRACKET);
		if(braceCount != -1)
			enclosureCheck(line, BRACE);
	}
			
	if(parCount != 0)
		printf("Parenthesis error.\n");
	if(bracketCount != 0)
		printf("Bracket error.\n");
	if(braceCount != 0)
		printf("Brace error.\n");
		
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

/* Updates the relevant enclosure count based on the specified enclosure
in line, returning and setting the count to -1 in the case of a leading
closing enclosure. */
int enclosureCheck(char line[], Enclosure enclosure) {
	char opening, closing;
	int *count, i;
	
	switch(enclosure) {
		case PARENTHESIS:
			opening = '(';
			closing = ')';
			count = &parCount;
			break;
		case BRACKET:
			opening = '[';
			closing = ']';
			count = &bracketCount;
			break;
		case BRACE:
			opening = '{';
			closing = '}';
			count = &braceCount;
			break;
	}
	
	for(i = 0; line[i]; ++i) {
		if(readState == OUT) {
			if(line[i] == '/' && line[i + 1] == '*') {
				readState = IN_COMMENT;
				continue;
			}
			else if(line[i] == '\'') {
				readState = IN_S_QUOTE;
				continue;
			}
			else if(line[i] == '\"') {
				readState = IN_D_QUOTE;
				continue;
			}
		}
		/* Prevents \' and \" from being recognised as syntactically
		relevant. */
		else if((readState == IN_S_QUOTE || readState == IN_D_QUOTE)
			&& line[i] == '\\') {
			++i;
			continue;
		}
		
		if(readState == OUT) {
			if(line[i] == opening)
				++(*count);
			else if(line[i] == closing) {
				if(*count == 0) {
					*count = -1;
					return -1;
				}
				else
					--(*count);
			}
		}
		else if((readState == IN_COMMENT && line[i] == '*'
			&& line[i + 1] == '/')
			|| (readState == IN_S_QUOTE && line[i] == '\'')
			|| (readState == IN_D_QUOTE && line[i] == '\"'))
			readState = OUT;
	}
	
	return 0;
}
