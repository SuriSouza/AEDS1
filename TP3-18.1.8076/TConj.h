#include <stdlib.h>
#include <stdio.h>


typedef struct 
{
	int *item;
	int n;
}TConj;

void inicializar(TConj*);
void imprimir(TConj);

int inserir_elemento(TConj*, int);
int excluir_elemento(TConj*, int);

int set_elemento(TConj*, int, int);
int get_elemento(TConj, int, int*);
int testar_elemento(TConj, int);

TConj gerar_conjunto(int);
TConj num2conj(int);

int conj2num(TConj);
int comparar(TConj, TConj);

TConj uniao(TConj, TConj);
TConj inter(TConj, TConj);
TConj subtrair(TConj, TConj);
