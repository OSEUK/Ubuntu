#include <stdio.h>
#include <math.h>

int main(void)
{
	double i;	// 제곱근이기 때문에 실수로 정의
	for (i=1.0; i<11; i++){	//1~10
		printf("sqrt(%.1lf) = %.4lf\n",i, sqrt(i)); //소수 4자리까지 출력
	}
	return 0;
}

