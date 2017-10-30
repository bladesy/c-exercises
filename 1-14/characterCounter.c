#include <stdio.h>
/* Count and present the frequency of different characters appearing
within the input */
int main() {
	/* Analyse input */
	/* Variable delcarations */
	int c, i, j, chars[26], digits[10];
	/* Array initialisations */
	for(i = 0; i < 26; ++i)
		chars[i] = 0;
	for(i = 0; i < 10; ++i)
		digits[i] = 0;
	/* Character counter */
	while((c = getchar()) != EOF)
		if(c >= '0' && c <='9')
			/* To obtain the actual value, and not the ASCII
			value, we subtract the ASCII value of 0, as
			subtracting '0' by '0' results in actual 0, and
			since all the other digit values are all grouped
			together, '0' subtracted from '1' gives actual
			1 */
			++digits[c - '0'];
		else if(c >= 'A' && c <= 'Z')
			/* The uppercase characters are grouped together
			just like the digits */
			++chars[c - 'A'];
		else if(c >= 'a' && c <= 'z')
			/* The lowercase characters are not grouped with
			the uppercase values, but they are with one
			another */
			++chars[c - 'a'];
	/* Print histogram */
	/* Separate printing loop for the digits, as different arrays
	are required */
	for(i = 0; i < 10; ++i) {
		/* If the count is 0, then move onto the next digit */
		if(!digits[i])
			continue;
		printf("The %c character occured %3d times: ", 
			i + '0', digits[i]);
		for(j = 0; j < digits[i]; ++j)
			putchar('#');
		putchar('\n');
	}
	/* Character printing loop */
	for(i = 0; i < 26; ++i) {
		if(!chars[i])
			continue;
		printf("The %c character occured %3d times: ", 
			i + 'A', chars[i]);
		for(j = 0; j < chars[i]; ++j)
			putchar('#');
		putchar('\n');
	}
	return 0;
}
