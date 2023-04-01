#include <stdio.h>

#define SIZE 100	// 배열의 사이즈 정의
#define OUT 0	
#define IN 1

int main(void)
{
	char c;				// 입력받는 문자 c 정의
	int state = IN;			// state를 IN으로 설정
	char ndigit[SIZE];		//배열 정의

	for (int i = 0; i < SIZE ; i++)
		ndigit[i] = 0;		// 배열 초기화
	int i=0;			// 반복문 내에서 쓸 변수 i 초기화
	while ((c = getchar()) != EOF)	// EOF 할때까지 반복
	{
		if (c == '\n'){		// 문장이 끝나면 (new line)
			for(int j=0; j<i; j++){				// i번 반복
				printf("%c",ndigit[j]);			// 0~i-1까지 입력된 문자들을 출력한다.
				if (ndigit[j] == ' ' || ndigit[j] == '\n' || ndigit[j] == '\t')		// 문장이 안 끝났는데 비어있다면
					state = OUT;			// state = OUT
				if (state == OUT){
					printf("\n");			// 단어마다 줄바꿈해서 출력하기 위함
					state = IN;			// 다시 IN
				}
				
			}
			printf("\n");	// 단어마다 문장 출력을 완료한 뒤 줄바꿈
			i = 0;		// 배열의 0번째부터 다시 채워넣기 위함(i 초기화)
		}
		
		else	{
			ndigit[i] = c;	// 문장이 끝나지 않으면 배열에 문자를 채워넣는다.
			i++;		// 계속 받기 
		}

	}
	return 0;
}
	
