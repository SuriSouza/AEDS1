#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, ano, mes, res, dia;
	scanf("%d", &x);

	ano = x / 365;
	res = x % 365;
	mes = res / 30;
	dia = res % 30;
	printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);

	return 0;
}