#include <stdio.h>
int i = 10;

void f(void)
{
	int i = 1;		// 지역변수 i = 1
	printf("i in f() is %d\n", i++);	//i를 출력하고 i++
}

void s(void)
{
	static int i = 100;	// 전역변수 i = 100
	printf("i in s() is %d\n", i++);	// i를 출력하고 i++
}

int main(void)
{
	for (int j = 0; j <3; ++j){
		printf("i in main() is %d\n", i++); // 프로그램 전체에 정의된 i는 증가하면서 출력
		f();		// f는 지역변수 i가 끝나면 초기화되므로 1만 출력
		s();		// s는 i가 static이므로 1씩 증가된 값 출력
	}
	return 0;
}
