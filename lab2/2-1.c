#include <stdio.h>

int main()
{
	double fahr, celsius;	// 화씨 섭씨 온도를 실수로 정의
	int lower, upper, step;

	lower = 0;	
	upper = 200;	//fahr 0부터 200까지 20단위
	step = 20;

	fahr = lower;	//fahr 0부터 시작하도록
	printf("fahrenheit \t celsius \n");	
	while (fahr <= upper)	// fahr이 upper보다 같거나 작을 동안 반복
	{
		celsius = 5.0/9.0*(fahr-32);	//실수 계산을 위해 5.0 9.0으로 	
		printf("%lf \t%lf \n", fahr, celsius);	//계산 후 출력
		fahr = fahr + step;	//fahr 20 증가 후 반복
	}
	return 0;
}

