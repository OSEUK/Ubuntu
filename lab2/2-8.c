#include <stdio.h>

int main(void)
{
	int i = 0X0F;	// 2진수로 변환 시 00001111
	int j = 0X14;	// 2진수로 변환 시 00010100

	printf("i & j = %X\n", i & j);	// 00000100 =  4
	printf("i | j = %X\n", i | j);	// 00011111 = 1F
	printf("i ^ j = %X\n", i ^ j);	// 00011011 = 1B
	printf("~(i | j) = %X\n",~(i | j));  // 11100000 이지만 4byte가 전부 not 되므로 FFFFFFE0
	printf("i<<2 = %X\n", i<<2);	// 00111100 = 3C
	printf("i>>3 = %X\n", i>>3);	// 00000001 = 1
	
	return 0;
}
