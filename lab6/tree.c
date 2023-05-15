#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main(void)
{	
	struct tnode *root;
	char word[MAXWORD];
	
	// root 초기화
	root = NULL;
	// EOF 눌릴 때까지 입력
	while (getword(word, MAXWORD) != EOF)
		// 단어가 알파벳이면 
		if (isalpha(word[0]))
			// addtree한다
			root = addtree(root, word);
	// 프린트
	treeprint(root);
	return 0;
}

