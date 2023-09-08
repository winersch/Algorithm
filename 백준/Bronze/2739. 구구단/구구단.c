#include<stdio.h>

int main() {
	int n,i;

	scanf("%d", &n);
	if ((n>=1)&&(n<=9))
	{
		for (i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", n, i, n*i);

		}

	}
	

	return 0;

}