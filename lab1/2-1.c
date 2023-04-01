#include <stdio.h>

int main()
{
	double fahrenheit, celsius; 
	int lower, upper, step;

	lower = 0;
	upper = 200;
	step = 20;

	fahrenheit = lower;
	printf("fahrenheit \t celsius\n");
	while (fahrenheit <= upper)
	{
		celsius = 5.0/9.0*(fahrenheit-32);
		printf("%lf \t %lf\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + step;
	}
	return 0;
}

