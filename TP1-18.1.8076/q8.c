#include <stdlib.h>
#include <stdio.h>

void swap(float *n1, float *n2)
{
	float aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

int main(int argc, char const *argv[])
{
	float n1, n2;
	scanf("%f", &n1);
	scanf("%f", &n2);

	swap(&n1, &n2);
	printf("%.1f\n", n1);
	printf("%.1f\n", n2);
	return 0;
}