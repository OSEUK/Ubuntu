#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	for(int i = 0; i < 4; i++){		// 4회 반복
		printf("%3d", rand() % 10);	// random을 10으로 나눈 나머지값 출력
	}
	printf("\n");

	return 0;
}
