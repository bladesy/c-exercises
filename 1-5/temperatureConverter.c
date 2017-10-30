#include <stdio.h>
/* Converts values of fahrenheit to celcius */
int main() {
	/* Variable declarations */
	int fahr; 
	/* Runs for each value of fahr between a lower and upper limit,
	at a constant interval */
	for(fahr = 300; fahr >= 0; fahr -= 20)
		/* Print the same temperature in both fahrenheit and
		celcius alongside each other */
		printf("%3d\t%3.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
	return 0;
}
