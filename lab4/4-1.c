#include <stdio.h>

int max(int i, int j, int k)
{
	if(i >= j){			// i >= j일때
		if(i >= k)
			return i;	// i가 k보다 크면 i값
		else
			return k;	// k가 i보다 크면 k값
	}
	else{				// j >= i 일때
		if(j >= k)
			return j;	// j가 k보다 크면 j
		else
			return k;	// k가 j보다 크면 k
	}
}
int min(int i, int j, int k)		// 최소값도 유사하게 코딩
{
	if(i <= j){
		if(i <= k)
			return i;
		else
			return k;
	}
	else{
		if(j <= k)
			return j;
		else
			return k;
	}
}
int main(void)
{
	int i = 10;
	int j = 20;
	int k = -30;

	printf("Min value is %d\n", min(i, j, k));
	printf("Max value is %d\n", max(i, j, k));

	return 0;
}
