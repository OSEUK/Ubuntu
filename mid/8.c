#include <stdio.h>
#include <ctype.h>

i
int main(int argc, char *argv[])
{
	double sum, average;
	
	for(int i=1; i<=argc; i++){
		
		sum += (double)((argv[i]));
		average = sum / argc;
	}
	printf("sum: %.6lf\n", sum);
	printf("average: %.6lf", average);

	return 0;
}	
