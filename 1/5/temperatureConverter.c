#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

/* Converts values of fahrenheit to celcius. */
int main(void) {
	int fahr; 
	
	/* Runs for each value of fahr between a lower and upper limit, at a
	constant interval. */
	for(fahr = UPPER; fahr >= LOWER; fahr -= STEP)
		/* Print the same temperature in both fahrenheit and
		celcius alongside each other */
		printf("%3d\t%3.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
	
	return 0;
}
