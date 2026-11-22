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

void montarGrado(GRAFO *grafo) {
    adicionarAresta(grafo, 0, 1, 5); // A -> B
    adicionarAresta(grafo, 0, 2, 12); // A -> C

    adicionarAresta(grafo, 1, 2, 6); // B -> C
    adicionarAresta(grafo, 1, 3, 14); // B -> D

    adicionarAresta(grafo, 2, 3, 7); // C -> D
    adicionarAresta(grafo, 2, 4, 18); // C -> E

    adicionarAresta(grafo, 3, 4, 8); // D -> E
}

void exibirGrafo(GRAFO *grafo) {
    printf("\n\t* REDE DE ATENDIMENTO *\t\n");

    for (int i = 0; i < QTD_VERTICES; i++) {
        printf("%c -> ", grafo->vertices[i].nome);

        ARESTA *atual = grafo->vertices[i].lista;

        if (atual == NULL) printf("Nenhum destino.");

        while(atual != NULL) {
            printf("%c (%d min)",
                grafo->vertices[atual->destino].nome,
                atual->tempo);

            atual = atual->prox;

            if (atual != NULL) printf(", ");
        }

        printf("\n");
    }
}

void liberarGrafo(GRAFO *grafo) {
    if (grafo == NULL) return;

    for (int i = 0; i < QTD_VERTICES; i++) {
        ARESTA *atual = grafo->vertices[i].lista;

        while (atual != NULL) {
            ARESTA *aux = atual;
            atual = atual->prox;

            free(aux);
        }
    }

    free(grafo);
}