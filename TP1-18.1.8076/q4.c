#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char nome[10];
	double salario, vendas;

	__fpurge(stdin);
	fgets(nome, 10, stdin);
	__fpurge(stdin);
	scanf("%lf", &salario);
	__fpurge(stdin);
	scanf("%lf", &vendas);

	printf("TOTAL = R$ %.2f\n", salario + (vendas*0.15));

	return 0;
}