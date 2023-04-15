#include <stdio.h>

int main(void)
{
	double sum = 1; //20!은 값이 너무 커서 double형으로 정의
	for(double i=1.0; i<=20; i++){ //i=1부터 20까지
		sum *= i;	//sum에 i를 곱하여 factorial 계산
		printf("%.lf! = %.lf\n",i,sum); //1!부터 20!까지 다 출력 (소수점 제거)
	}
	return 0;
}



