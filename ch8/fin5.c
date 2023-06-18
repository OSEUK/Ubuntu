#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char *str = {"C Programming 2 test, Enjoy!"};
	int i, l, n[123];
	char c;

	for (i='A'; i <= 'z'; ++i)
		n[i] = 0;
	while(*str) {
		if(isalpha(*str))
			n[*str]++;
		++str;
	}

	for (i='a', l=0; i <= 'z'; ++i)
		if (n[i])
			printf("%c : %d%c", i, n[i], (++l % 4) ? '\t' : '\n');

	putchar('\n');

	return 0;
}
