#include <stdio.h>
#include <string.h>

int mystrlen(char *s){
	int i=0;

	while(*s != '\0'){	//문자열의 마지막이 NULL로 채워졌기 때문에
		*s++;
		i++;
	}
	// 문자열을 0번째부터 검사, null이 아닐 시 i++한다.
	return i;
}

int main(void)
{
	char *s[] = {"This is Lab5", "Easy C Programming", "Have fun"};
	
	printf("with strlen()\n");
	int n = (int)(sizeof(s)/sizeof(char *));
	for (int i = 0; i < n; i++)
		printf("%s %d\n", *(s+i), (int)strlen(s[i]));
	// +i번째 문자열 출력, 그 문자열의 길이 출력
	putchar('\n');

	printf("with mystrlen()\n");
	for(int i = 0; i < n; i++)
		printf("%s %d\n", *(s+i), (int)strlen(s[i]));
	putchar('\n');
	
	return 0;
}
