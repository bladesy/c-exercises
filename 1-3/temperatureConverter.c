#include <stdio.h>
/* Converts values of fahrenheit to celcius */
int main() {
	/* Variable declarations */
	float fahr, 
		cel;
	int upper,
		lower,
		step;
	/* Variable initialisations */
	upper = 100;
	lower = 0;
	step = 20;
	/* Runs for each value of fahr between lower and upper, at
	intervals of step */
	for(fahr = lower; fahr < upper; fahr += step) {
		/* Calculate the value in celcius of the current
		temperature in fahrenheit */
		cel = (5.0/9.0) * (fahr - 32.0);
		/* Print the same temperature in both fahrenheit and
		celcius alongside each other */
		printf("%3.0f\t%3.1f\n", fahr, cel);
	}
	return 0;
}
