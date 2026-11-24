#include <stdio.h>
#include "../grafo.h"

int main() {
    GRAFO *grafo = criarGrafo();

    if (grafo == NULL) {
        return 1;
    }

    montarGrafo(grafo);

    exibirGrafo(grafo);

    int origem = 0;  // A
    int destino = 4; // E
    int encontrado;

    // Teste DFS
    printf("\n\t* TESTE DFS *\n");
    printf("Origem: %c\n", grafo->vertices[origem].nome);
    printf("Destino: %c\n", grafo->vertices[destino].nome);
    printf("Visitados: ");

    reiniciarBusca();

    encontrado = dfs(grafo, origem, destino);

    exibirResultado(grafo, encontrado);

    // Teste BFS
    printf("\n\t* TESTE BFS *\n");
    printf("Origem: %c\n", grafo->vertices[origem].nome);
    printf("Destino: %c\n", grafo->vertices[destino].nome);
    printf("Visitados: ");

    reiniciarBusca();

    encontrado = bfs(grafo, origem, destino);

    exibirResultado(grafo, encontrado);

    liberarGrafo(grafo);

    return 0;
}