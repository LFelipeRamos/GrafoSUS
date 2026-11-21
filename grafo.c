#include<stdio.h>
#include "grafo.h"

GRAFO *criarGrafo() {
    GRAFO *grafo = malloc(sizeof(GRAFO));

    if (grafo == NULL) {
        printf("Erro durante alocação da memória para o grafo./n");
        return NULL;
    }

    for (int i = 0; i < QTD_VERTICES; i++) {
        grafo->vertices[i].nome = 'A' + i;
        grafo->vertices[i].lista = NULL;
    }

    return grafo;
}

void adicionarAresta(GRAFO *grafo, int origem, int destino, int tempo) {
    ARESTA *nova = malloc(sizeof(ARESTA));

    if (nova == NULL) {
        printf("Erro durante alocação de memória para aresta./n");
        return;
    }

    nova->destino = destino;
    nova->tempo = tempo;

    nova->prox = grafo->vertices[origem].lista;

    grafo->vertices[origem].lista = nova;
}