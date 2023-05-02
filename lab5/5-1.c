#include <stdio.h>

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int *p = a;	//a의 주소 p
	int i;

	for (i=0; i<5; i++)	 
		printf("%2d", a[i]);	// 배열의 인덱스 호출
	putchar('\n');
	i = 0;
	while(i<5){
		printf("%2d", *(p++));	// p의 주소를 1씩 증가시킨후 그 값
		i++;
	}
	putchar('\n');
	return 0;
}
