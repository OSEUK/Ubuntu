#include <stdio.h>

void b(int *p)
{
	printf("%d %d %d\n", p[0], p[-1], p[-2]); 
	// 그 주소의 값부터 0, -1,-2번째 주소의 값 출력
	return;
}

int main(void)
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int n = (int)(sizeof(a)/sizeof(int));	// 배열 요소의 개수
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');

	b(a+n-1);
	// a배열의 주소(첫번째 요소)에서 배열크기인 10만큼 더한 뒤 -1을 뺀다. 
	// = a[9]의 주소 
	
	return 0;
}
