#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

void push(double);	// 사용하게될 함수 미리 정의
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {	//getop가 EOF일때까지
		switch (type) {			//연산자 타입별 출력
			case NUMBER:
				push(atof(s)); //문자열 숫자를 실수로변경 
				break;
			case '+':
				push(pop() + pop());	//위 두개 pop해서 더함
				break;
			case '*':
				push(pop() * pop());	//위 두개 pop해서 곱함	
				break;
			case '-':
				op2 = pop();		// 먼저 뽑은걸 나중에 뺌
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();		//먼저 뽑은 걸 나중에 나눔
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");//op2(분모)가 0이면 나눌 수 없음.
				break;
			case '\n':
				printf("\t%.8g\n", pop());	//최종 연산값 출력
				break;
			default:
				printf("error: unknown command %s\n", s); // 연산자가 아니면 error
				break;
		}
	}
	return 0;
}

