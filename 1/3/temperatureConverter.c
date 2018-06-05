#include <stdio.h>

#define UPPER 100
#define LOWER 0
#define STEP 20

/* Converts values of fahrenheit to celcius. */
int main(void) {
	float fahr, cel;
	
	/* Runs for each value of fahr between lower and upper, at intervals
	of step. */
	for(fahr = LOWER; fahr < UPPER; fahr += STEP) {
		/* Calculate the value in celcius of the current temperature in
		fahrenheit. */
		cel = (5.0/9.0) * (fahr - 32.0);
		/* Print the same temperature in both fahrenheit and celcius
		alongside each other. */
		printf("%3.0f\t%3.1f\n", fahr, cel);
	}
	
	return 0;
}
