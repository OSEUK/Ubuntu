#include <stdio.h>

double factorial(int n){
	if(n == 1)
		return 1;	//n 이 1이면 종료
	else
		return n*factorial(n-1);	// n*factorial(n-1)을 호출한다.
}
int main(void)
{
	for(int i =1 ; i<20; i++)	//20까지 반복
	{
		printf("%2d! = %.lf\n", i, factorial(i));	// 출력
	}
	return 0;
}

