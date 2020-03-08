#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);

	if(N > 10000)
		N = 10000;

	printf("%d\n", N*N);

	return 0;
}