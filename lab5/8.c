#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
	double sum=0;
	double avg=0;
	double num;
	// 합과 평균, 문자를 숫자로 바꾼 num 정의
	for(int i=0; i < argc-1; i++){
		num = atof(*++argv);	//atof사용 변환
		sum += num;	// 더함
	}
	avg = sum / (argc-1);	// 평균을 argc-1로 나눔

	printf("sum: %lf\n", sum);
	printf("average: %lf\n",avg);	//출력

	return 0;
}

