#include "TConj.h"
#include <time.h>
#include <math.h>

#define MAX 10

/* Declaração dos conjuntos e inicialização de A. */

void inicializar(TConj *pA)
{
	int i;
	pA->n = 10;
	pA->item = malloc(MAX * sizeof(TConj));
}

/* 
 * Função que vai inserir elementos em A 
 * Realoca seu tamanho caso queira inserir mais elementos
 * Realloc é feito de 10 em 10.
 */

int inserir_elemento(TConj *pA, int elem)
{
	int i, j, cont=0;

	for(i=0; i < pA->n; i++)
	{
		if(pA->n-1 <= i)
		{
			pA->n += 10;
			pA->item = (TConj*) realloc(pA->item, sizeof(TConj*) * pA->n);
		}
		if(pA->item[i] == NULL)
		{
			pA->item[i] = elem;
			return 1;
		}
	}
	return 0;
}

/* 
 * Função que exclui aleatoriamente elementos em A
 * caso encontre-os. Em seguida, imprime o novo conjunto.
 */

int excluir_elemento(TConj *pA, int elem)
{
	int i, cont=0;
	for(i=0; i < pA->n; i++)
	{
		if(pA->item[i] == elem)
		{
			pA->item[i] = NULL;
			cont++;
		}
		if(cont > 0)
		{
			pA->item[i] = pA->item[i+1];
		}
	}
	return cont;
}

/* 
 * Função que "seta" um elemento no conjunto A
 * na posição passada por parâmetro.
 */

int set_elemento(TConj *pA, int elem, int pos)
{
	if(pos <= pA->n-1)
	{
		pA->item[pos] = elem;
		return 1;
	}
	else
		return 0;
}

/* 
 * Função que recupera um elemento no conjunto A.
 * Caso a posição passada exista no vetor, ela retorna 1, senão 0.
 * Além disso, a variável passada por referência recebe o elemento dessa posição.
 */

int get_elemento(TConj pA, int pos, int *pelem)
{
	int i;
	for(i=0; i < pA.n; i++)
	{
		if(i == pos)
		{
			*pelem = pA.item[pos];
			return 1;
		}
	}
	return 0;
}

/*
 * Função que verifica se o elemento passado está no vetor.
 * Caso esteja retorna sua posição, senão -1.
 */

int testar_elemento(TConj pA, int elem)
{
	int i;
	for(i=0; i < pA.n; i++)
	{
		if(pA.item[i] == elem)
		{
			return i;
		}
	}
	return -1;
}

/* 
 * Função que gera um conjunto aleatoriamente e o retorna.
 */

TConj gerar_conjunto(int n)
{
	int i;
	TConj B;
	B.n = n;
	B.item = malloc(B.n * sizeof(TConj));

	for(i=0; i < n; i++)
	{
		B.item[i] = 10 + rand() % 40;
	}
	return B;
}

/*
 * Função que gera um conjunto à partir de um número passado por parâmetro.
 * Em seguida retorna o conjunto.
 */

TConj num2conj(int num)
{
	int i = 0, j = 0, resto = 0, aux = num;

	do{
		aux = aux / 10;
		i++;
	}while(aux > 1);

	TConj C;
	C.item = malloc(i * sizeof(TConj));
	
	aux = num;

	do{
		resto = aux % 10;
		aux = aux / 10;
		C.item[j] = resto;
		j++;
		i--;
	}while(i > 0);

	return C;
}

/*
 * Função inversa à anterior. Gera um número à partir do conjunto e o retorna.
 */

int conj2num(TConj B)
{
	long int num = 0;
	int tam, i;
	tam = B.n;

	for (i = 0; i < B.n; ++i)
	{
		num += B.item[i] * pow(10, (2 + tam));
		tam -= 2;
	}

	return num;
}

/*
 * Função que compara dois conjuntos e retorna 1 se são iguais
 * 0 se são diferentes.
 */

int comparar(TConj B, TConj C)
{
	int aux = 0;

	int i, j;
	if(B.n == C.n)
	{	
		for(i=0; i < B.n; i++)
		{
			for(j=0; j < C.n; j++)
			{
				if(B.item[i] == C.item[j])
				{
					aux = 1;
				}
			}
		}
	}
	return aux;
}

/* Função que imprime o conjunto */

void imprimir(TConj pA)
{
	int i;
	for(i=0; i < pA.n; i++)
	{
		if(pA.item[i] != 0)
			printf("%d, ", pA.item[i]);
	}
	printf("\n");
}

TConj uniao(TConj A, TConj B)
{
	TConj D;
	D.n = MAX;
	D.item = malloc(D.n * sizeof(TConj));
	int i;

	for(i=0; i < A.n; i++)
	{
		inserir_elemento(&D, A.item[i]);
	}

	for (i = 0; i < B.n; ++i)
	{
		inserir_elemento(&D, B.item[i]);
	}
	
	return D;
}

TConj inter(TConj A, TConj B)
{
	int i, j;
	TConj D;
	D.n = MAX;
	D.item = malloc(D.n * sizeof(TConj));

	for (i = 0; i < A.n; i++)
	{
		for (j = 0; j < B.n; j++)
		{	
			if(A.item[i] == B.item[j])
			{
				D.item[i] = B.item[i];
			}
		}
	}

	return D;
}

TConj subtrair(TConj A, TConj B)
{
	int i, j;
	TConj D;
	D.n = A.n;
	D.item = malloc(D.n * sizeof(TConj));

	for (i = 0; i < A.n; i++)
	{
		for (j = 0; j < B.n; j++)
		{
			if (A.item[i] != B.item[j] && A.item[i] != 24)
			{
				D.item[i] = A.item[i];
			}
		}
	}

	return D;
}
