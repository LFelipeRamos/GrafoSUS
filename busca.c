#include <stdio.h>
#include "grafo.h"

int visitados[QTD_VERTICES];
int caminho[QTD_VERTICES];

int qtdVertices;
int qtdArestas;
int qtdCaminho;

// Reinicia os dados da busca
void reiniciarBusca() {
    for (int i = 0; i < QTD_VERTICES; i++) {
        visitados[i] = 0;
    }

    qtdVertices = 0;
    qtdArestas = 0;
    qtdCaminho = 0;
}

// Busca em profundidade (DFS)
int dfs(GRAFO *grafo, int atual, int destino) {
    visitados[atual] = 1;
    qtdVertices++;

    caminho[qtdCaminho++] = atual;

    printf("%c ", grafo->vertices[atual].nome);

    if (atual == destino) {
        return 1;
    }

    ARESTA *aresta = grafo->vertices[atual].lista;

    while (aresta != NULL) {
        int proximo = aresta->destino;

        if (!visitados[proximo]) {
            qtdArestas++;

            if (dfs(grafo, proximo, destino)) {
                return 1;
            }
        }

        aresta = aresta->prox;
    }

    qtdCaminho--;

    return 0;
}

// Busca em largura (BFS)
int bfs(GRAFO *grafo, int origem, int destino) {
    int fila[QTD_VERTICES];
    int anterior[QTD_VERTICES];

    int inicio = 0;
    int fim = 0;

    for (int i = 0; i < QTD_VERTICES; i++) {
        anterior[i] = -1;
    }

    fila[fim++] = origem;
    visitados[origem] = 1;

    while (inicio < fim) {
        int atual = fila[inicio++];

        qtdVertices++;

        printf("%c ", grafo->vertices[atual].nome);

        if (atual == destino) {
            // Registra o caminho na ordem inversa
            int v = destino;

            while (v != -1) {
                caminho[qtdCaminho++] = v;
                v = anterior[v];
            }

            // Inverte o caminho
            for (int i = 0; i < qtdCaminho / 2; i++) {
                int temp = caminho[i];

                caminho[i] = caminho[qtdCaminho - 1 - i];
                caminho[qtdCaminho - 1 - i] = temp;
            }

            return 1;
        }

        ARESTA *aresta = grafo->vertices[atual].lista;

        while (aresta != NULL) {
            int proximo = aresta->destino;

            if (!visitados[proximo]) {
                visitados[proximo] = 1;
                anterior[proximo] = atual;

                fila[fim++] = proximo;
                qtdArestas++;
            }

            aresta = aresta->prox;
        }
    }

    return 0;
}

void exibirResultado(GRAFO *grafo, int encontrado) {
    printf("\nVertices visitados: %d", qtdVertices);
    printf("\nArestas percorridas: %d", qtdArestas);

    if (encontrado) {
        printf("\nObjetivo encontrado: Sim");
        printf("\nCaminho: ");

        for (int i = 0; i < qtdCaminho; i++) {
            printf("%c ", grafo->vertices[caminho[i]].nome);
        }
    } else {
        printf("\nObjetivo encontrado: Nao");
    }

    printf("\n");
}