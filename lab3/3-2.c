#include <stdio.h>
#include <string.h>

#define SIZE 100 	// 계산 문자들이 들어갈 배열
#define BUFSIZE 100 	// getch함수를 만들기 위해서

char buf[BUFSIZE];
int bufp = 0;

int getch(void)		//입력 버퍼로 인한 오류 막기 위해 getch함수 정의
{
	return (bufp >0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch : too many characters\n");
	else
		buf[bufp++] = c;
}

double result(double x, double y, char op) // 결과값을 낼 함수 정의
{
	switch(op){
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return y == 0 ? 0 : x / y;	// y가 0이 아닐때만 나누기 값 출력
		case '%':
			return y == 0 ? 0 : ((int)x % (int)y); // 나머지는 정수 계산이기 때문
		default : 
			return 0;	// 아니면 return 0;
	}
}

int main(void)
{
	char c, op;			// 문자를 받을 c와 연산자 op
	double x = 0.0, y = 0.0;	// 피연산자 정의
	double k = 0.1;			// 소수점 이하를 계산하기 위해 정의
	int is_double = 0;		// 소수점 유무를 계산하기 위해
	int i = 0, j = 0;		// 문자를 배열로 관리하기 위해 

	char line[SIZE] = { 0 };	// 배열 초기화
	
	while((c = getch()) != EOF)	// EOF 입력 될때까지
	{
		if (c == '\n'){		// enter입력시 계산
			for(j = 0; line[j] >= '0' && line[j] <= '9'; j++){
				x = x * 10.0 + (line[j] - '0');				// 첫번째 숫자 입력되는 동안 숫자 계산
			}
			if(line[j] == '.'){						// 소수점이 들어가면
				is_double = 1;						// 실수형이다.
				for(++j; line[j] >= '0' && line[j] <= '9'; j++){ 	// 소수점 이후부터 숫자나오는동안 소수점 계산
					x = x + k * (line[j] - '0');			// 소수점이하추가
					k *= 0.1;					// 소수점 이하가 커질수록 k도 작아짐
				}
				k = 0.1;						// 계산이 끝나면 k 초기화
			}
			
			op = line[j]; 							// 첫 숫자 이후의 문자를 연산자로 간주

			for(j++; line[j] >= '0' && line[j] <= '9'; j++){ 		// 다음 숫자를 y에 대입
				y = y*10.0 + (line[j] - '0');
			}
			if(line[j] == '.'){
				is_double = 1;
				for(j++; line[j] >= '0' && line[j] <= '9'; j++){
					y = y + k * (line[j] - '0');
					k *= 0.1;
				}
				k = 0.1;
			}

			if (is_double == 1)						// 둘 중 하나라도 실수형이라면
				printf("%lf\n", result(x, y, op));			// 실수형으로
			else
				printf("%d\n", (int)result((int)x, (int)y, op));	// 정수형으로
			x = y = i = j = is_double = 0; 					// 모든 변수 초기화
			op = ' '; 							// 연산자도 초기화
			memset(line, 0, sizeof(line)); 					// 배열 초기화
		}
		else {
			if(c == ' ' || c == '\t'); 					// 띄어쓰기나 탭이면 배열에 넣지 않음.
			else{
				line[i] = c;
				i++;
			}
		}
	}
	return 0;
}

			

