#include <stdio.h>
#define SIZE 100
int main(void)
{
	char c, ch;
	int v[SIZE] = {0};
	int i = 0, j = 0;
	int count, othercount;
	while((c = getchar()) != EOF){
		v[i] = c;
		i++;
	}
	for(ch ='A'; ch <= 'Z'; ch++){
		count = 0;
		for(j = 0; j <= SIZE; j++){
			if(v[j] == ch || v[j] == ch + 32)
				count++;
		}
		i -= count;
	if(count > 0)
		printf("%c/%c count: %d\n",ch, ch+32, count);

	}
	printf("Oters:%d\n ",i);
	return 0;
}

	
	
