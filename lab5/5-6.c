#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
	int c;
        int reverse = 0;	// -r option을 받을 변수
	int k = argc;		// k에 argc를 넣는다.
	while (--argc > 0 && (*++argv)[0] == '-')   // 첫번째 입력이 '-'이면
		while(c = *++argv[0])	// -다음이 r이면
			switch (c) {
			case 'r':
				reverse = 1;	// -r이면 reverse에 1 대입
				break;
			default:
				break;
			}
	if( reverse  == 1){	// reverse이면
		for(int i = 0; *argv != NULL; i++)	
			*argv++;
		// 문자열 끝으로 이동
		for(int i = 0; i < k-2 ; i++)
		       printf("%s ",*--argv);
		// ./5-6과 -r 제외 마지막 단어부터 출력
	}
	else	
		for(int i = 0; i < k-1; i++)
			printf("%s ",*argv++);
		// 원래 순서대로 출력
	putchar('\n');

	return 0;
}	
