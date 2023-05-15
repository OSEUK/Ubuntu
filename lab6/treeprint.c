#include <stdio.h>
// tnode 정의
struct tnode {
        char *word;
        int count;
        struct tnode *left;
        struct tnode *right;
};


void treeprint(struct tnode *p)
{	
	// NULL이 아니면
	if (p != NULL) {
		treeprint(p->left); // root를 기준으로 왼쪽부터
		printf("%4d %s\n", p->count, p->word); 
		treeprint(p->right); // 오른쪽으로 print한다.
	}
}
