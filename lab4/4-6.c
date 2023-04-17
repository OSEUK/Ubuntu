#include <stdio.h>
void qsort(double v[], int left, int right)
{
	int i, last;
	void swap(double v[], int i, int j);	//v[i]와 v[j]값을 바꾸는 함수

	if(left >= right)	// left가 right보다 크거나 같다면(정렬할 값이 하나 이하이면)
		return;		// 정렬 x
	swap(v, left, (left + right)/2);	// v[left]와 중앙값 변경
	last = left;				// last에 left를 대입
	for ( i = left+1; i <= right; i++)	// last + 1부터 마지막 요소까지 (pivot의 위치 설정)
		if(v[i] < v[left])		// v[i]가 v[left]보다 작다면
			swap(v, ++last, i);	// 자리를 바꾸고  v[++last]와 v[i]를 교환
	swap(v, left, last);			// v[left]와 v[last]변경 (pivot이 last의 위치로 감.)
	qsort(v, left, last-1);			// last는 고정하고 왼쪽 오른쪽 따로 정렬
	qsort(v, last+1, right);
}
void swap(double v[], int i, int j)	//v[i]와 v[j]를 교환하는 함수.
{
	double temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define ELEMENTS 10

int main(void) {
	
	double array[] = {1.1, 9.9, 2.2, 8.8, 3.3, 7.7, 4.4, 6.6, 5.5, 0.0};
	
	for(int i = 0; i < ELEMENTS; i++)
		printf("%5.1lf",array[i]);	//소수점한자리 출력.
	printf("\n");

	qsort(array, 0, 9);
	
	for(int i=0; i<ELEMENTS; i++)
		printf("%5.1lf",array[i]);
	printf("\n");
	return 0;
}
