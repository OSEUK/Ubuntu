#include <stdio.h>

int main(void)
{	
	int k;	//int형 k 
	for(int i=2; i<=200; i++){	// i는 2부터 200까지
		k = 0;	//k를 0으로 초기화
		for(int j=2; j<i/2;j++){ //200까지이면 100부터는 의미 없으므로 2부터 i/2까지 
		       if( i%j == 0 ){ //i/j가 나누어 떨어지면
			     k=1; //k에 1 대입
		       } 
		}
		if(k == 0)	//나누어 떨어지는 수가 없다면
			printf("%d ",i);	//출력
	}
	
	return 0;
}
