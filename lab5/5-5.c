#include <stdio.h>

static char daytab[2][13] = {		// daytab 정의
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)	// day_of_year 함수
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;	// 윤년 여부
	for (i = 1; i < month; i++)
		day += daytab[leap][i];		// 몇 번째 날인지
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)	// month_day함수
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;	// 윤년 여부
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];	// 몇월 몇일인지
	*pmonth = i;
	*pday = yearday;
}

int main(void)
{
	printf("2022년 5월 5일은 %d번째 날입니다.\n",day_of_year(2022, 5, 5));
	printf("2014년 5월 5일은 %d번째 날입니다.\n",day_of_year(2014, 5, 5));
	// day_of_year활용하여 출력
	
	int pmonth, pday;

	month_day(2022,200, &pmonth, &pday);
	printf("2022년 200일 째는 %d월 %d일 입니다.\n", pmonth, pday);
	month_day(2022,300, &pmonth, &pday);
	printf("2022년 300일 째는 %d월 %d일 입니다.\n", pmonth, pday);
	// month_day로 pmonth, pday값을 받아온 후 출력

	return 0;
}

