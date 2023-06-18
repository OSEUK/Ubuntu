#include <stdio.h>

int main(void)
{
	FILE *f1, *f2;

	f1 = fopen("text.txt", "r");
	f2 = fopen("text1.txt", "w");
	char buf[256];
	int n;

	for(int i=0; i<3; i++){
		fseek(f1, (i!=2)?10:-10, i);
		n = fread(buf, 1, 5, f1);
		fwrite(buf, 1, n, f2);
		fputc('\n', f2);
	}
	fclose(f1);
	fclose(f2);

	return 0;
}
