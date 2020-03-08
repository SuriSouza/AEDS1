#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c1, c2, l1, l2, i, j;

	float **mat1, **mat2;
	scanf("%d", &l1);
	scanf("%d", &c1);
	
	mat1 = malloc(l1 * sizeof(float*));
	for(i=0; i < l1; i++)
	{
		mat1[i] = malloc(c1 * sizeof(float));
	}

	for(i=0; i < l1; i++)
	{
		for(j=0; j < c1; j++)
		{
			scanf("%f", &mat1[i][j]);
		}
	}

	scanf("%d", &l2);
	scanf("%d", &c2);

	mat2 = malloc(l2 * sizeof(float*));
	for(i=0; i < l2; i++)
	{
		mat2[i] = malloc(c2 * sizeof(float));
	}

	for(i=0; i < l2; i++)
	{
		for(j=0; j < c2; j++)
		{
			scanf("%f", &mat2[i][j]);
		}
	}

	if(l1==l2 && l2==c1 && c1==c2)
	{
		for(i=0; i < l1; i++)
		{
			for(j=0; j < c1; j++)
			{
				mat1[i][j] = mat1[i][j] + mat2[i][j];
				printf("%.2f ", mat1[i][j]);
			}
			printf("\n");
		}
	}

	for(i=0; i < l1; i++)
	{
		free(mat1[i]);
	}
	free(mat1);
	for(j=0; j < l2; j++)
	{
		free(mat2[j]);
	}
	free(mat2);

	return 0;
}