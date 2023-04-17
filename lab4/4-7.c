#include <stdio.h>
#include <string.h>

#define NAMELEN 10
#define ELEMENT 7

void qsort(char v[][NAMELEN], int left, int right)
{
	int i, last;
	void swap(char v[][NAMELEN], int i, int j);	//v[i]와 v[j]값을 바꾸는 함수

	if(left >= right)	// left가 right보다 크거나 같다면(정렬할 값이 하나 이하이면)
		return;		// 정렬 멈춤
	swap(v, left, (left + right)/2);	// 중앙값을 맨 왼쪽으로 이동(비교하기 편하게)
	last = left;				// last = left값(pivot)
	for ( i = left+1; i <= right; i++)	// left + 1부터 마지막 요소까지 pivot 위치 설정
		if(strcmp(v[i] , v[left]) < 0)		// v[i]가 작다면 음수 반환
			swap(v, ++last, i);	// 자리를 바꾸고  v[++last]와 v[i]를 교환
	swap(v, left, last);			// left와 last의 자리를 바꾼다. v[last]를 기준으로 왼쪽은 작은값, 오른쪽은 큰값으로 정렬(last = pivot)			
	qsort(v, left, last-1);			// last를 기준으로 왼쪽 오른쪽 정렬.
	qsort(v, last+1, right);
}
void swap(char v[][NAMELEN], int i, int j)
{
	char temp[NAMELEN];
	
	strcpy(temp, v[i]);	// 문자열을 바꾸기 위해 strcpy 함수를 사용했다.
	strcpy(v[i], v[j]);
	strcpy(v[j], temp);
}



int main(void) {
	
	char array[ELEMENTS][NAMELEN] = {"kim", "lee","park","choi","jung","kang","cho"};

	for(int i = 0; i < ELEMENTS; i++)
		printf("%s ",array[i]);		// ELEMENT 만큼 문자열 출력
	
	printf("\n");

	qsort(array, 0, ELEMENTS-1); // 정렬
	
	for(int i=0; i<ELEMENTS; i++)
		printf("%s ",array[i]);

	printf("\n");
	
	return 0;
}
