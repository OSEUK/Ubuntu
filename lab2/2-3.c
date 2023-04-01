#include <stdio.h>

int main(void)
{
	int i = 65;

	printf("%d\n", i);	//일반적인 정수형
	printf("%o\n", i);	// 8진수에서 사용
	printf("%X\n", i);	// 16진수에서  사용
	printf("%c\n", i);	// char형에서 사용
	printf("%f\n", i);	//실수형에서 사용
	printf("%e\n", i);	//지수형으로 표현. 자릿수를 이동시킴
	printf("%g\n", i);	//유효자릿수가 6자리가 넘어가면 지수형, 넘어가지 않으면 실수형.

	return 0;
}
