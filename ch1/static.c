#include <stdio.h>

int a()
{
	static int i = 10;
	printf("%d ", i++);
}
int main()
{
	for(int j=0;j<3; j++)
		a();

	return 0;
}
