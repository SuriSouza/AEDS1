#include <stdio.h>
#include <stdlib.h>

#include "TConj.h"

int main(int argc, char const *argv[])
{
	/* Declaração dos conjuntos e inicialização de A. */
	TConj A, B, C, D;
	int elemento, num, i;
	inicializar(&A);

	/* 
	 * Função que vai inserir elementos em A 
	 * Realoca seu tamanho caso queira inserir mais elementos
	 * Realloc é feito de 10 em 10. Por fim, imprime seu conjunto.
	 */

	printf("Inserir elementos: A\n");
	srand(171);
	for(i=0; i < 10; i++)
	{
		inserir_elemento(&A, rand() % 40);
	}	
	imprimir(A);

	/* 
	 * Função que exclui aleatoriamente elementos em A
	 * caso encontre-os. Em seguida, imprime o novo conjunto.
	 */

	printf("\nExcluir elementos: A\n");
	srand(171);
	for(i=0; i < 10; i++)
	{
		excluir_elemento(&A, rand() % 20-1);
	}
	imprimir(A);

	/* 
	 * Função que "seta" um elemento no conjunto A
	 * na posição passada por parâmetro.
	 */
	printf("\nSetar um elemento: A\n");
	set_elemento(&A, 9, 3);
	imprimir(A);

	/* 
	 * Função que recupera um elemento no conjunto A.
	 * Caso a posição passada exista no vetor, ela retorna 1, senão 0.
	 * Além disso, a variável passada por referência recebe o elemento dessa posição.
	 */

	printf("\nRecuperar elemento: %d\n", get_elemento(A, 5, &elemento));

	/*
	 * Função que verifica se o elemento passado está no vetor.
	 * Caso esteja retorna sua posição, senão -1.
	 */

	printf("\nTestar elemento: A\n");
	if(testar_elemento(A, 9) == -1)
		printf("\nO elemento 9 nao esta presente em A\n");
	else
		printf("O elemento 9 esta presente em A\n");


	/* 
	 * Função que gera um conjunto aleatoriamente e o retorna.
	 */

	printf("\nGerar conjunto: B\n");
	B = gerar_conjunto(4);
	printf("{%d, ", B.item[0]);
	for (i = 1; i < 4-1; i++)
	{
		printf("%d, ", B.item[i]);
	}
	printf("%d}\n", B.item[4-1]);

	/*
	 * Função que gera um conjunto à partir de um número passado por parâmetro.
	 * Em seguida retorna o conjunto.
	 */

	printf("\nGerar conjunto a partir de um numero: C\n");
	C = num2conj(25378);
	printf("{%d, ", C.item[4]);
	for (i = 3; i > 0; i--)
	{
		printf("%d, ", C.item[i]);
	}
	printf("%d}\n", C.item[0]);

	/*
	 * Função inversa à anterior. Gera um número à partir do conjunto e o retorna.
	 */

	printf("\nGerar numero a partir de um conjunto: B\n");
	num = conj2num(B);
	printf("Numero: %d\n", num);

	/*
	 * Função que compara dois conjuntos e retorna 1 se são iguais
	 * 0 se são diferentes.
	 */

	printf("\nComparar dois conjuntos: B | C\n");
	if(comparar(B, C) == 1)
		printf("Os conjuntos sao iguais\n");
	else
		printf("Os conjuntos sao diferentes\n");
	
	printf("\nUniao de conjuntos: A + B\n");
	D = uniao(A, B);
	imprimir(D);
	
	printf("\nIntersecção de conjuntos: A e B\n");
	D = inter(A, B);
	imprimir(D);
	
	printf("\nSubtracao de conjuntos: A - B\n");
	D = subtrair(A, B);
	imprimir(D);

	return 0;
}