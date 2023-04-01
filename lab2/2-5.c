#include <stdio.h>
#include <limits.h>

int main(void)
{
	char num1 = CHAR_MIN;	// char 의 최소값
	char num2 = CHAR_MAX;	// char 의 최대값
	short num3 = SHRT_MIN;	// short 의 최소값
	short num4 = SHRT_MAX; 	// short 의 최대값
	int num5 = INT_MIN;	// int의 최소값
	int num6 = INT_MAX;	// int의 최대값
	long num7 = LONG_MIN;	// long의 최소값
	long num8 = LONG_MAX;	// long의 최대값
	unsigned char num9 = UCHAR_MAX;	// unsigned char의 최대값
	unsigned short num10 = USHRT_MAX; // unsigned short의 최대값
	unsigned int num11 = UINT_MAX;	// unsigned int의 최대값
	unsigned long num12 = ULONG_MAX; // unsigned long의 최대값
	// unsigned 자료형의 최소값은 0이므로 보이지 않음.
	

	printf("%d %d\n", num1, num2);
	printf("%d %d\n", num3, num4);
	printf("%d %d\n", num5, num6);
	printf("%ld %ld\n", num7, num8);
	printf("%u\n %u\n", num9, num10);
	printf("%u\n %lu\n", num11, num12);
	
	return 0;
}
		


	

