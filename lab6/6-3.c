#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"defalut", 0,
	"do", 0,
	"double", 0,
	"else", 0,
	"enum", 0,
	"extern", 0,
	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,
	"int", 0,
	"long", 0,
	"register", 0,
	"return", 0,
	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,
	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0,	
};

// getword와 binsearch 선언
int getword (char *, int);
int binsearch(char *, struct key *, int);

int main(void)
{
	int n;
	char word[MAXWORD];
	
	// 입력이 끝날때까지
	while (getword(word, MAXWORD) != EOF)
		// word[0]이 알파벳이면서
		if (isalpha(word[0]))
			// binsearch값이 0보다 크다면
			if((n = binsearch(word, keytab, NKEYS)) >= 0)
				// keytab[n]의 count가 증가한다.
				keytab[n].count++;
	for (n=0; n<NKEYS; n++)
		// count가 증가한다면 ( 입력된 keyword라면)
		if(keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}
// 이진 탐색
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	
	// 0 ~ NKEYS-1 까지
	low = 0;
	high = n-1;
	while (low <= high) {
		mid = (low + high) / 2;
		// word가 tab[mid].word보다 작으면
		if ((cond = strcmp(word, tab[mid].word)) < 0 )
			// 왼쪽 부분
			high = mid - 1;
		// 반대이면
		else if (cond >0)
			// 오른쪽
			low = mid + 1;
		// 일치한다면
		else
			return mid;
	}
	// 일치하는 word가 없다면 -1 반환
	return -1;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	// 띄어쓰기 체크
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	// 알파벳이 아니면 끝에 null입력 후 c 반환
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	// lim이 0보다 큰 동안
	for ( ; --lim > 0; w++)
		// 입력받은 숫자가 알파벳이나 숫자가 아니면 탈출
		if(!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
	// 정상적일 때 word반환
}
