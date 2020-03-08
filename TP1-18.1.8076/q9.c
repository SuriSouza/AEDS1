#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

	char resp;
	FILE *file1 = fopen("argv[1]", "r");
	fprintf(file1, "Line 1\nLine 2\nLine 3\nFinal line\n");
	FILE *file2 = fopen("argv[2]", "w");
	
	if(file2 != NULL)
	{
		printf("Deseja sobreescrevê-lo? [S/N]: ");
		scanf("%c", &resp);
	}

	char leitor[100];
	if(resp == 'S')
	{
		while(fgets(leitor, 100, file1) != NULL)
		fputs(leitor, file2);
	}

	fclose(file1);
	fclose(file2);

	return 0;
}