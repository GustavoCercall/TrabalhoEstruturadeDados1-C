#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


int main() {

    int i;
    int **grafo;
    Pilha p;
    int dimensao, verticeInicial;
    scanf("%d", &dimensao);
    grafo = inicializa_grafo(dimensao);
    int *status_vertices = (int *) malloc(dimensao * sizeof(int));
    scanf("%d", &verticeInicial);
    printf("---------------\n");

    for (i = 0; i < dimensao; i++) {
        status_vertices[i] = 0;
    }

    inicializa_pilha(&p, dimensao);

    empilha(&p, verticeInicial);

    while (pilha_vazia(p) != 1) {
        int temp;
        desempilha(&p, &temp);
        
        if (status_vertices[temp - 1] == 0) {
            printf("%d\n", temp);
            status_vertices[temp - 1] = 1;

            for (i = 0; i < dimensao; i++) {
                if (grafo[temp - 1][i] == 1) {
                    if (status_vertices[i] == 0) {
                        empilha(&p, i + 1);
                    }
                }
            }
        }
    }

    return 1;
}
