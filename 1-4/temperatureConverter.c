#include <stdio.h>
/* Converts values of celcius to fahrenheit */
int main() {
	/* Variable declarations */
	float cel, 
		fahr;
	int upper,
		lower,
		step;
	/* Variable initialisations */
	upper = 100;
	lower = 0;
	step = 20;
	/*Runs for each value of cel between lower and upper, at
	intervals of step */
	for(cel = lower; cel < upper; cel += step) {
		/* Calculate the value in fahrenheit of the current
		temperature in celcius */
		fahr = (9.0/5.0) * cel + 32.0;
		/* Print the same temperature in both celcius and
		fahrenheit alongside each other */
		printf("%3.0f\t%3.1f\n", cel, fahr);
	}
	return 0;
}
