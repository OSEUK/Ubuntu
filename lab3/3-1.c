#include <stdio.h>

int main(void)
{
	int x, y;

	printf("두 개의 정수를 입력하세요:");
	scanf("%d %d",&x,&y);		//두 개의 정수를 입력받음.

	if( x < y )			// y가 x보다 크다면
		printf("%d - %d = %d\n", y,x,y-x);  //y에서 x를 뺌.
	else
		printf("%d - %d = %d\n", x,y,x-y); //아니면 x-y.

	return 0;
}
		
