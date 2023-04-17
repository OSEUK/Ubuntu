#include <stdio.h>
#include <ctype.h>

void push(double);
double pop(void);

int getch(void);
void ungetch(int);

#define NUMBER '0'

int getop(char s[]) // 연산자를 받는 함수
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;		// 공백문자가 나오는동안
	s[1] = '\0';		//s[1] = NULL
	if(!isdigit(c) && c != '.') //숫자가 아니거나 '.'이면  반복
		return c;		// 연산자 return 
	i = 0;
	if (isdigit(c))			// 숫자이면
		while (isdigit(s[++i] = c = getch()))
			;	//배열에 계속 숫자 넣음
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;	//배열에 계속 .넣음
	s[i] = '\0';		//문자열 끝에 NULL
	if (c != EOF)		// EOF가 아니면
		ungetch(c);	// ungetch(c)c
	return NUMBER; //문자가 아니면 return NUMBER
}
