#include <stdio.h>

#define ALPHACHARS 26
#define DIGITCHARS 10

/* Count and present the frequency of different characters appearing
within the input. */
int main(void) {
	int c, i, j, chars[ALPHACHARS], digits[DIGITCHARS];
	
	/* Array initialisations. */
	for(i = 0; i < ALPHACHARS; ++i)
		chars[i] = 0;
	for(i = 0; i < DIGITCHARS; ++i)
		digits[i] = 0;
	
	/* Character counter. */
	while((c = getchar()) != EOF)
		if(c >= '0' && c <='9')
			/* To obtain the actual digit, and not the ASCII value, we
			subtract the ASCII value of 0, as subtracting '0' from '0'
			results in 0 - this working for all digits as ASCII keeps
			them in order. */
			++digits[c - '0'];
		else if(c >= 'A' && c <= 'Z')
			++chars[c - 'A'];
		else if(c >= 'a' && c <= 'z')
			++chars[c - 'a'];
	
	/* Print histogram. */
	/* Digit printing. */
	for(i = 0; i < DIGITCHARS; ++i) {
		/* If the count is 0, then move onto the next digit. */
		if(!digits[i])
			continue;
		printf("The %c character occured %3d times: ", i + '0',
			digits[i]);
		for(j = 0; j < digits[i]; ++j)
			putchar('#');
		putchar('\n');
	}
	/* Character printing. */
	for(i = 0; i < ALPHACHARS; ++i) {
		if(!chars[i])
			continue;
		printf("The %c character occured %3d times: ", i + 'A',
			chars[i]);
		for(j = 0; j < chars[i]; ++j)
			putchar('#');
		putchar('\n');
	}
	
	return 0;
}
