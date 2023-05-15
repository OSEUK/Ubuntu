#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);	
void writelines(char *lineptr[], int nlines);

void Qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *)); 
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;	// numeric order로 정렬할 여부 결정

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	// -n으로 시작한다면 numeric order로 정렬
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		Qsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
		// numeric이 1이면 숫자 크기대로, 0이면 사전 순으로 정렬한다.
		putchar('\n');
		printf("After sort.\n");
		// EOF가 입력되면 줄바꿈 한 뒤 After sort로 구분되게 함
		writelines(lineptr, nlines);
		// 순서대로 출력
		return 0;
	} 
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}
#include <stdlib.h>
// atof사용 위함
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	// 문자 두 개를 받아 실수형으로 변환
	if( v1 < v2 )
		return -1;
	else if( v1 > v2)
		return 1;
	else
		return 0;
	// v1이 작으면 -1, v1이 크면 1, 같으면 0 반
}
