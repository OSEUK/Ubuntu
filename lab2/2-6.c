#include <stdio.h>

int htoi(char s[])
{
	int n = 0;
	int i = 0;

	while (s[i] != '\0'){	//배열이 비어 있을 때까지 반복
		if (s[i] >= '0' && s[i] <= '9'){  //0~9기준 아스키코드
			n = n*16 + (s[i] - '0');  
		}
		else if (s[i] >= 'a' && s[i] <= 'f') {  // a~f기준 아스키코드
			n = n*16 + (s[i] - 'a' + 10);	// 10을 더해서 a이면 10으로 인식하게 함 
		}
		else if (s[i] >= 'A' && s[i] <= 'F') {	// 대문자도 동일
			n = n*16 + (s[i] - 'A' + 10);
		}
		else
			break;	//다른 알파벳이면 break;
		i++;	//첫번째 문자가  끝나면 다음 문자실행 
	}
	return n; //최종 n값 return
}

int main(void)
{
	char h[] = "12AF";

	printf("%s\n", h);
	printf("%x\n", htoi(h));	// 16진수 소문자로 출력
	printf("%d\n", htoi(h));	// integer(10진수)

	return 0;
}
