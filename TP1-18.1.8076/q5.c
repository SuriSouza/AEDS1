#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int X;
	float Y;
	scanf("%d", &X);
	scanf("%f", &Y);

	printf("%.3f km/l\n", (float) X/Y);
	
	return 0;
}