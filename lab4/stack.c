#include <stdio.h>

#define MAXVAL 100
void push(double);
double pop(void);

int getop(char []);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)	//stack에 가득차지않으면
		val[sp++] = f;	//sp에 f를 넣고 ++
	else
		printf("error: stack full, can't push %g\n", f); //full stack
}

double pop(void)
{
	if (sp > 0)		//sp가 비어있지 않다면
		return val[--sp];//--sp return 
	else {
		printf("error: stack empty\n");	//empty stack
		return 0.0;	//double 형
	}
}
