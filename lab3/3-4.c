#include <stdio.h>

int main()
{
	int x, y, temp;
	char c;

	scanf("%d %d", &x, &y);	// 정수를 입력받음

	if(x > y){
		temp = x;
		x = y;
		y = temp;
	}			// x가 둘 중  더 작은 값이 되도록 바꿈.
	
	for (int i=1;i<=x;i++){
		if(x%i == 0 && y%i == 0) // x와 y를 i로 나눈값이 둘다 나누어 떨어진다면 공약수
			printf("%d ",i);			
	}
	printf("\n");

	return 0;
}
