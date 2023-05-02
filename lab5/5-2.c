#include <stdio.h>

int main(void)
{
	int a[][3] = {{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}};
	int *pa[] = {a[0], a[1], a[2]};	// a의 각 행을 가리키는 포인터
	int *p = a[0];	// a[0][i]의 요소를 가리키는 포인터

	int i;
	for (i = 0; i < 3; i++)
		printf("%d %d %d\n", a[i][2-i], *a[i], *(*(a+i)+i));
	// a[i][2-i]는 a[0][2],a[1][1] 처럼 출력
	// *a[i]는 a[i]의 첫번째 값을 가리키므로 a[i][0]값들을 출력
	// *(*(a+i)+i)는 *(a+i)는 행 주소, 그 행에서 +i번째 값을 출력 == a[i][i]
	
	putchar('\n');

	for (i = 0; i < 3; i++)
		printf("%d %d\n", *pa[i], p[i]);
	// *pa[i]는 각자 a[0],a[1],a[2]를 가리키므로 주소의 첫번째 값을 출력
	// p[i]는 a[0]의 주소이므로 a[0][i]번째 값을 출력
	
	putchar('\n');

	return 0;
}
