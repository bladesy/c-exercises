#include <stdio.h>

#define UPPER 100
#define LOWER 0
#define STEP 20

/* Converts values of celcius to fahrenheit. */
int main(void) {
	float cel, fahr;

	/*Runs for each value of cel between lower and upper, at intervals
	of step. */
	for(cel = LOWER; cel < UPPER; cel += STEP) {
		/* Calculate the value in fahrenheit of the current temperature
		in celcius. */
		fahr = (9.0/5.0) * cel + 32.0;
		/* Print the same temperature in both celcius and fahrenheit
		alongside each other. */
		printf("%3.0f\t%3.1f\n", cel, fahr);
	}
	
	return 0;
}
