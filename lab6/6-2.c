#include <stdio.h>

int main(void)
{
	// 구조체 node 정의
	struct node {
		int len;
		char* str;
	};
	
	// node 값 설정
	struct node a[] = {5, "hello", 10, "world"};
	// pointer p는 a의 첫번째 주소를 가리킨다.
	struct node *p = a;
	
	// a[0]의 len은 5, str은 "hello" 이다.
	printf("a[0].len is %d\n", a[0].len);

	// pointer p도 같은 곳을 가리키므로 len은 5, str은 hello를 출력한다.
	printf("p->len is %d\n", p->len);
	printf("p->str is %s\n", p->str);

	// *p++->str은 p->str의 첫번째 문자를 출력한 뒤 pointer의 주소를 증가시킨다. "h"출력
	printf("*p++->str is %c\n", *p++->str);

	// 위에서 pointer가 증가되었으므로 p의 len은 10, str은 world를 출력한다.
	printf("p->len is %d\n", p->len);
	printf("p->str is %s\n", p->str);

	return 0;
}
