#include <stdio.h>
#define NUM int		//NUM을 int로 정의
#define OUT printf	//OUT을 printf로 정의
#define PI 3.14		//PI를 3.14로 정의
#define SQ(X) ((X)*(X)) //SQ(X) 를((X)*(X))로 정의

NUM main()
{
	NUM a,b,c;	//int a,b,c;
	a = (NUM)PI;	//(int)PI
	b = 25;
	c = a + b;
	OUT("Result %d\n", SQ(c));	//result ((C)*(C))
	return 0;
}
