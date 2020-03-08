#include "sort.h"

// Bubble Sort
void bubbleSort(TArray *pA, long *att, long *comp){
	TItem aux;
	int i, j;

	for(i=1; i < pA->n; i++)
	{
		for(j=0; j < pA->n-1; j++)
		{
			/* Condição vai verificar se o valor na posição [j] é maior que valor 
			 * na posição [j+1]. Se for, realiza as atribuições (troca/swap). Senão, j incrementa +1.*/
			(*comp)++;
			if(pA->item[j].key > pA->item[j+1].key)
			{
				(*att) += 3;
				aux			  = pA->item[j];
				pA->item[j]   = pA->item[j+1];
				pA->item[j+1] = aux;
			}
		}
	}
}

// Bubble Sort Otimizado
void bubbleSortO(TArray *pA, long *att, long *comp){
	int i, j;
	TItem aux;

	// for de fora vai 1 posição a menos
	for(i=0; i < pA->n-1; i++)		  // otimizado
	{
		// j vai até n-i-1 para evitar comparar com a mesma posição
		for(j=0; j < pA->n-i-1; j++)  // otimizado
		{
			/* Condição vai verificar se o valor na posição [j] é maior que valor 
			 * na posição [j+1]. Se for, realiza as atribuições (troca/swap). Senão, j incrementa +1.*/
			(*comp)++;
			if(pA->item[j].key > pA->item[j+1].key)
			{
				(*att) += 3;
				aux 		  = pA->item[j];
				pA->item[j]   = pA->item[j+1];
				pA->item[j+1] = aux;
			}
		}
	}
}

// Selection Sort
void selectSort(TArray *pA, long *att, long *comp){
	int i, j, min;
	TItem aux;

	for(i=0; i < pA->n-1; i++)
	{
		// variável que marcar o menor valor/posição
		min = i;
		for(j = i+1; j < pA->n; j++)
		{
			// se valor na posição j for menor que valor na posição min, então min recebe a posição j
			// valor na posição min se torna o menor valor verificado
			(*comp)++;
			if(pA->item[j].key < pA->item[min].key)
			{
				min = j;
			}
		}
		// se os valores nas posições i e min forem diferentes, a troca é realizada
		if(pA->item[i].key != pA->item[min].key)
		{
			(*att) += 3;
			aux 		  = pA->item[i];
			pA->item[i]   = pA->item[min];
			pA->item[min] = aux;
		}
	}
}

// Selection Sort otimizado
void selectSortO(TArray *pA, long *att, long *comp){
	int i, j, min;
	TItem aux;

	for(i=0; i < pA->n-1; i++)
	{
		// variável que marcar o menor valor/posição
		min = i;
		for(j=i+1; j < pA->n; j++)
		{
			// se valor na posição j for menor que valor na posição min, então min recebe a posição j
			// valor na posição min se torna o menor valor verificado
			(*comp)++;
			if(pA->item[min].key > pA->item[j].key)
			{
				min = j;
			}
		}
		// ao invés de comparar os valores, é comparado a posição para evitar atribuições desnecessárias
		if(min != i)
		{
			(*att) += 3;
			aux = pA->item[i];
			pA->item[i] = pA->item[min];
			pA->item[min] = aux;
		}
	}
}

// Insertion Sort
void insertionSort(TArray *pA,long *att,long *comp){
	int i, j;
	TItem aux;

	for(i=1; i <= pA->n-1; i++)
	{
		(*att)++;
		// é atribuído à variável auxiliar o valor na posição i
		aux = pA->item[i];
		j = i-1;
		// o while funciona enquanto j >= 0 e enquanto o valor de aux for menor que 
		// valor do array na posição
		while((j >= 0) && (aux.key < pA->item[j].key))
		{
			// enquanto aux for menor, a troca é realizada
			(*comp)++;
			(*att)++;
			pA->item[j+1] = pA->item[j];
			j--;
		}
		(*att)++;
		pA->item[j+1] = aux;
	}
}

// Insertion Sort Otimizado
void insertionSortO(TArray *pA, long *att, long *comp){
	int i, j;
	TItem aux;

	for(i=1; i < pA->n; i++)
	{
		(*att)++;
		// é atribuído à variável auxiliar o valor na posição i
		aux = pA->item[i];
		j = i;
		// ao invés de verificar se j > 0, o while só funciona enquanto o valor de aux for menor que 
		// valor do array na posição
		while(pA->item[j-1].key > aux.key)
		{
			(*comp)++;
			(*att)++;
			// enquanto aux for menor, a troca é realizada
			pA->item[j] = pA->item[j-1];
			j--;
		}
		(*att)++;
		pA->item[j] = aux;
	}
}

// Shell Sort
void shellSort(TArray* pA, long* att, long* comp){
	int i, j, gap = 1;
	TItem aux;

	// enquanto gap for menor que n ele é atribuído 3 * gap + 1
	while(gap < pA->n)
	{
		(*comp)++;
		gap = 3 * gap + 1;
	}
	while(gap > 0)
	{
		for(i=gap; i < pA->n; i++)
		{
			(*att)++;
			aux = pA->item[i];
			j = i;
			while(j > gap-1 && aux.key <= pA->item[j-gap].key)
			{
				(*comp)++;
				(*att)++;
				pA->item[j] = pA->item[j-gap];
				j = j - gap;
			}
			(*att)++;
			pA->item[j] = aux;
		}
		gap = gap/3;
	}
}

// Quick Sort
void quickSort(TArray* pA, long* att, long* comp){
	int i, j;
	TItem pivo, aux;
	// é escolhido um pivor para colocá -lo na posição correta
	pivo = pA->item[(0 + pA->n-1) / 2];

	i = 0;
	j = pA->n - 1;

	// while vai funcionar enquanto i (inicializado como 0) foi menor ou igual a j (inicializado com n-1) 
	while(i <= j)
	{
		// verifica se os valores menores que o pivo estão à esquerda dele
		(*comp)++;
		while(pA->item[i].key < pivo.key)
		{
			i++;
		}
		// verifica se os valores menores que o pivo estão à direita dele
		while(pA->item[j].key > pivo.key)
		{
			j--;
		}
		if(i <= j)
		{
			// caso o pivo não esteja na sua posição correta, realiza a troca
			(*att) += 3;
			aux = pA->item[i];
			pA->item[i] = pA->item[j];
			pA->item[j] = aux;
			i++;
			j--;
		}
	}
}

// Heap Sort 
void heapSort(TArray* pA, long* att, long* comp){
	int n = pA->n;
	int i = n / 2, pai, filho;
	TItem t;

	while(i >= 0)
	{
		if(i > 0)
		{
			// se i for menor que 0, i decrementa 1 e t recebe o valor do array na posição i
			(*att)++;
			i--;
			t = pA->item[i];
		}
		else
		{
			(*att)+=2;
			n--;
			// se o tamanho do vetor for igual a 0, retorna nada
			if(n == 0) return;
			// senão t recebe o último valor do array 
			t = pA->item[n];
			// última posição recebe o valor da primeira posição
			pA->item[n] = pA->item[0];
		}
		// como heap é uma árvore binária
		// tem-se o pai (nó/chave) que deve ser maior ou igual aos filhos
		pai = i;
		filho = i * 2 + 1;
		// while funciona enquanto a posição filho for menor que o tamanho do vetor
		while(filho < n)
		{
			(*comp)++;
			// incrementa a posição filho se o valor na posição filho +1 for maior que filho
			if((filho + 1 < n) && (pA->item[filho+1].key > pA->item[filho].key))
			{
				(*att)++;
				filho++;
			}
			// se valor na posição filho for maior que a chave, a troca é realizada
			if(pA->item[filho].key > t.key)
			{
				(*att)++;
				pA->item[pai] = pA->item[filho];
				pai = filho;
				filho = pai * 2 + 1;
			}
			else{ break; }
		}
		// valor na posição pai (nó) recebe o maior valor 
		// isso no caso do heap max
		pA->item[pai] = t;
	}
}

// Merge Sort
void mergeSort(TArray* pA, long* att, long* comp){
	int comeco1, meio, fim1, comeco2, fim2;

	if(pA->n > 1)
	{
		comeco1 = 1;
		meio = (comeco1 + pA->n) / 2;
		fim1 = meio;
		comeco2 = meio+1;
		fim2 = pA->n;
	}

	int n1 = meio - comeco1 + 1;
	int n2 = fim2 - meio;
	int i, j, k;

	// creating vectors left and right
	TItem L[n1], R[n2];
	for(i=0; i < n1; i++)
	{
		(*comp)++;
		L[i] = pA->item[comeco1+i];
	}
	for(j=0; j < n2; j++)
	{
		(*comp)++;
		R[j] = pA->item[meio+1+j];
	}

	i = j = k = 0;
	while(i < n1 && j < n2)
	{
		(*comp)++;
		if(L[i].key <= R[j].key)
		{
			(*att)++;
			pA->item[k] = L[i];
			i++;
		}
		else
		{
			(*att)++;
			pA->item[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		(*comp)++;
		pA->item[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		(*comp)++;
		pA->item[k] = R[j];
		j++;
		k++;
	}
}