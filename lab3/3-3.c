#include <stdio.h>

void shellsort(int v[], int n)
{
	int gap, i, j, temp;	

	for (gap = n/2; gap > 0; gap /=2) 		//배열의 크기의 n/2만큼 자른다. 
		for(i=gap; i<n; i++)			//i는 gap부터 n-1까지 i++한다.
			for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){ // 앞에있는 숫자가 뒤에있는 숫자보다 크면 바꾸는 일을 반복.
				temp = v[j];	
				v[j] = v[j+gap];
				v[j+gap] = temp; 	// 두 수를 비교하여 정렬
			}
}
int main(void)
{
	int s[] = {12, 73, 4, 51, 22, 71, 2, 68, 100, 35};
	int i;
	int m = sizeof(s)/sizeof(int);	//배열속 원소의 개수

	for (i=0; i<m; i++)
		printf("%4d", s[i]);	// s[i]를 프린트함
	putchar('\n');			//줄바꿈

	shellsort(s,m);			//정렬
	for(i=0; i<m; i++)
		printf("%4d", s[i]);
	putchar('\n');

	return 0;
}
