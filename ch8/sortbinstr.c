#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p, const void *q)
{
	return( strcmp((char *)p, (char *)q));
}
	
int main(void)
{
	char a[][10] = {"banana", "apple", "orange", "carrot", "tomato"};

	int num = sizeof(a) / sizeof(a[0]);
	int i;

	for (i = 0; i < num; i++)
		printf("%s ", a[i]);
	printf("\n");
	
	qsort(a, num, sizeof(a[0]), compare);

	for (i = 0; i < num; i++)
		printf("%s ", a[i]);
	printf("\n");

	char * found;
	char * key = "orange";
	if ((found = bsearch(key, a, num, sizeof(a[0]), compare)) != NULL)
		printf("Found key is %s.\n", found);
	else
		printf("There is no %s in List.\n", key);

	key = "oop";
	if ((found = bsearch(key, a, num, sizeof(a[0]), compare)) != NULL)
		printf("Found key is %s\n.", found);
	else
		printf("There is no %s in List.\n", key);

	return 0;
}
