#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tn {
	char *w;
	struct tn *l;
	struct tn *r;
};

struct tn *add(struct tn *p, char *w)
{
	if(p==NULL) {
		p = (struct tn *)malloc(sizeof(struct tn));
		p->w = w;
		p->l = p->r = NULL;
	}
	else if ( strcmp(w, p->w) < 0)
		p->l = add(p->l, w);
	else
		p->r = add(p->r, w);
	return p;
}

void tprint(struct tn *p)
{
	if (p!= NULL) {
		tprint(p->r);
		printf("%s\n", p->w);
		tprint(p->l);
	}
}

int main(void)
{
	char *str[] = {"This", "is", "test", "for", "add", "and", "print"};
	struct tn *r;
	r = NULL;

	int num = (int)(sizeof(str) / sizeof(char *));

	for (int i = 0; i < num; i++)
		r = add(r, str[i]);
	tprint(r);

	return 0;
}
