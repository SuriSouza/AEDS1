#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	float x1, x2, y1, y2;

	scanf("%f%f", &x1, &y1);
	scanf("%f%f", &x2, &y2);

	printf("%.4f\n", sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)));
	return 0;
}