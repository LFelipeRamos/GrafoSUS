#include<stdio.h>
#include "grafo.h"

GRAFO *criarGrafo() {
    GRAFO *grafo = malloc(sizeof(GRAFO));

    if (grafo == NULL) {
        printf("Erro durante alocação da memória./n");
        return NULL;
    }

    for (int i = 0; i < QTD_VERTICES; i++) {
        grafo->vertices[i].nome = 'A' + i;
        grafo->vertices[i].lista = NULL;
    }

    return grafo;
}