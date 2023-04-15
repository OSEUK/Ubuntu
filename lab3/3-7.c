#include <stdio.h>

int main(void)
{
	int asc;	//ASCII코드 변수

	for (asc = 33; asc <= 126; asc++){	//33 ~ 126까지
		printf("%d %X %c ",asc, asc, asc); // 10진수 16진수 문자로 표현
	}
	return 0;
}

