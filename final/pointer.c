#include <stdio.h>

int main(void)
{
	int a[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *pa[] = {a[2], a[1], a[0]};
	int *pp = a[0];

	printf("%d %d %d\n", a[0][0], a[1][1], a[2][2]);
	printf("%d %d %d\n", *pa[0], *pa[1], *pa[2]);
	printf("%d %d %d\n", *pp, *(pp+1), *(pp+2));

	return 0;
}
