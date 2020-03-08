#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashlp.h"

extern int M; // size of linear probing table

int main(){

	int i, sum_cost;
	srand(time(0));

	printf("Tamanho da tabela: ");
	scanf("%d", &M);

	init_hash();

	// Adding key-values

	for(i=0; i < (M * 0.5); i++)
		put(rand() % rand() + 1 , rand() % rand() + 1);

	int random = rand() % rand() + 1;
	put(random, 100.0);

	printf("Displaying only inseted key-values \n\n");
	display();

	for(i=0; i < M; i++)
		if(del(random) != -1)
			printf("\nkey-value deleted\n");

	printf("\nDisplaying all hash table \n\n");
	display_all();

	printf("\nDisplaying hash table as '*'' and '_' respectivelly occupied and empty slots.\n\n");
	display_clusters();

	//You also can check the insertion
	if( put(123456, 1.2) == 0 ){
		printf("Error: table is full.\n");
	}else{
		printf("key-value inserted.\n");
	}

	if( put(33242, 34.75) == 0 ){
		printf("Table is full.\n");
	}else{
		printf("key-value inserted.\n");
	}
	
	printf("\nKey: %d -> Count: %d\n", random, count_search_miss(random));
	
	return 0;
}