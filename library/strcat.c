/* concatenate t to end of s; */
#include <stdio.h>

void strca(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
}
