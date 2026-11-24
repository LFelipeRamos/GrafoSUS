#ifndef GRAFO_H
#define GRAFO_H

#define QTD_VERTICES 5

typedef struct aresta {
    int destino;
    int tempo;
    struct aresta *prox;
} ARESTA;

typedef struct {
    char nome;
    ARESTA *lista;
} VERTICE;

typedef struct {
    VERTICE vertices[QTD_VERTICES];
} GRAFO;

GRAFO *criarGrafo();
void adicionarAresta(GRAFO *grafo, int origem, int destino, int tempo);
void montarGrafo(GRAFO *grafo);
void exibirGrafo(GRAFO *grafo);
void liberarGrafo(GRAFO *grafo);

void reiniciarBusca();
int dfs(GRAFO *grafo, int atual, int destino);
int bfs(GRAFO *grafo, int origem, int destino);
void exibirResultado(GRAFO *grafo, int encontrado);

#endif