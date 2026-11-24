
#include <stdio.h>
#include <ctype.h>
#include "grafo.h"

int selecionarVertice(GRAFO *grafo, const char *mensagem) {
    char entrada[64];
    char vertice, extra;

    while (1) {
        printf("%s (A-E): ", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return -1;
        }

        if (sscanf(entrada, " %c %c", &vertice, &extra) == 1) {
            vertice = toupper((unsigned char) vertice);

            for (int i = 0; i < QTD_VERTICES; i++) {
                if (grafo->vertices[i].nome == vertice) {
                    return i;
                }
            }
        }

        printf("Vertice invalido. Tente novamente.\n");
    }
}

void executarBusca(GRAFO *grafo, int opcao) {
    int origem = selecionarVertice(grafo, "Origem");
    if (origem == -1) return;

    int destino = selecionarVertice(grafo, "Destino");
    if (destino == -1) return;

    reiniciarBusca();

    printf("\n===== RESULTADO DA %s =====\n",
           opcao == 2 ? "DFS" : "BFS");

    printf("Origem: %c\n", grafo->vertices[origem].nome);
    printf("Destino: %c\n", grafo->vertices[destino].nome);
    printf("Visitados: ");

    int encontrado;

    if (opcao == 2) {
        encontrado = dfs(grafo, origem, destino);
    } else {
        encontrado = bfs(grafo, origem, destino);
    }

    exibirResultado(grafo, encontrado);
}

int main(void) {
    GRAFO *grafo = criarGrafo();

    if (grafo == NULL) {
        return 1;
    }

    montarGrafo(grafo);

    int opcao;
    char entrada[64], extra;

    while (1) {
        printf("\n========== GRAFO SUS ==========\n");
        printf("1 - Visualizar rede de atendimento\n");
        printf("2 - Busca em profundidade (DFS)\n");
        printf("3 - Busca em largura (BFS)\n");
        printf("0 - Sair\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;
        }

        if (sscanf(entrada, "%d %c", &opcao, &extra) != 1) {
            printf("Opcao invalida!\n");
            continue;
        }

        switch (opcao) {
            case 1:
                exibirGrafo(grafo);
                break;

            case 2:
            case 3:
                executarBusca(grafo, opcao);
                break;

            case 0:
                liberarGrafo(grafo);
                printf("Programa encerrado.\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
        }
    }

    liberarGrafo(grafo);
    return 0;
}
