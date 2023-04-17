#include <stdio.h>
#include <stdlib.h> // srand 를 사용하기 위함
#include <time.h>   // time을 사용하기 위함

int main(void)
{
	srand((unsigned int)time(NULL));	// 현재 시간을 기준으로 rand 시드 변경

	for(int i = 0; i <4; i++){		// 4-2와 동일
		printf("%3d", rand() % 10);
	}
	printf("\n");

	return 0;
}
