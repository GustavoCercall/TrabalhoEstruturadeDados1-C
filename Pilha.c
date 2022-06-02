#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void inicializa_pilha ( Pilha *p, int c ){
	p->dados = malloc( sizeof(int) * c );
	p->capacidade = c;
	p->topo = -1;
}

int pilha_vazia ( Pilha p ) {
	return p.topo == -1;
}

int pilha_cheia ( Pilha p ) {
	return p.topo == p.capacidade - 1;
}

int empilha ( Pilha *p, int info ) {
	if( pilha_cheia ( *p ) )
		return ERRO_PILHA_CHEIA;

	p->topo++;
	p->dados[p->topo] = info;
	return 1; // Sucesso
}

int desempilha ( Pilha *p, int *info ) {
	if ( pilha_vazia ( *p ) )
		return ERRO_PILHA_VAZIA;

	*info = p->dados[p->topo];
	p->topo--;
	return 1; // Sucesso
}

void mostra_pilha ( Pilha p ) {
	if( pilha_vazia ( p ) )
		printf("Pilha vazia!\n");
	else{
		printf("Dados da Pilha:\n");
		int i;
		for( i=0 ; i <= p.topo ; i++)
			printf("%d\n", p.dados[i]);
   }
}

void desaloca_pilha( Pilha *p ){
	free( p->dados );
}

int **inicializa_grafo(int dimensao){

    int i, j;
    FILE *fp;
	int **grafo = (int **) malloc(dimensao * sizeof(int *));
	
	for (i = 0; i < dimensao; i++) {
		grafo[i] = (int *) malloc(dimensao * sizeof(int));
	}

	fp = fopen("texto.txt", "r");

    for (i = 0; i < dimensao; ++i)
    {
        for (j = 0; j < dimensao; ++j)
        {
            fscanf(fp, "%d", grafo[i] + j);
        }
    }

	fclose(fp);
	
	return grafo;
}

void mostra_grafo(int **grafo, int dimensao){
	printf("Dados da matriz %dx%d:\n", dimensao, dimensao);
	int i, j;
	for(i = 0 ; i < dimensao; i++){
		for( j = 0 ; j < dimensao ; j++ )
			printf("%4d ", grafo[i][j]);
		printf("\n");
	}
	printf("\n");
}
