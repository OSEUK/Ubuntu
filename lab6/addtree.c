#include <stdio.h>
#include <string.h>

struct tnode {
        char *word;
        int count;
        struct tnode *left;
        struct tnode *right;
};

struct tnode *talloc(void);
char *Strdup(char *s);

// node를 추가하는 함수
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	
	// p가 null이면
	if (p == NULL) {
		// 메모리를 할당받은 후 word와 count를 채운다. 좌 우 자식노드는 NULL.
		p = talloc();
		p->word = Strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	// p가 null이 아니면서
	// w가 p->word와 같다면 count++
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	// w가 작다면 왼쪽에, w가 크다면 오른쪽에 노드 추가
	else if ( cond < 0 )
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

#include <stdlib.h>

// tnode 구조체의 크기만큼 메모리를 할당받는다.
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

// string.h에 strdup이 있어서 바꿔서 만듬
// 입력받은 문자열 copy해서 반환
char *Strdup(char *s)
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}
