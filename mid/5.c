#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int c, nl, nw, nc, state; //문자열과 라인, 단어, 개수를 센다.
	
	state = OUT;	//상태를 저장

	nl = nw = nc = 0;
	while ((c=getchar()) != EOF)	// EOF가 눌릴때까지 받는다.
	{
		++nc;	//입력될 때마다 newcharacter
		if (c == '\n')	// 엔터누르면 new line
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')	// 공백이나 탭문자가 있으면 state out
			state = OUT;
		else if (state == OUT)
		{
			state = IN;	// 단어 구별
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);

	return 0;
}
