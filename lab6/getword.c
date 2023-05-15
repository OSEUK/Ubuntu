#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	// 공백문자 무시
	while (isspace(c = getch()))
		;
	// EOF가 아니면
	if (c != EOF)
		*w++ = c;
	// 알파벳이 아니면 null문자 추가 후 return 
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	// lim이 0보다 큰 동안
	for ( ; --lim > 0 ; w++)
		// 받은 문자가 알파벳이나 숫자가 아니면
		// break
		if(!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	// 완료되면 null문자 추가
	*w = '\0';
	// 단어 반환
	return word[0];
}
