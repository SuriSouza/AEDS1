#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	double pi = 3.14159, r;
	scanf("%lf", &r);
	double A = pi * (r*r);
	printf("A=%.4lf\n", A);

	return 0;
}