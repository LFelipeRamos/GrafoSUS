#include <stdio.h>
#include "../grafo.h"

int main() {
    GRAFO *grafo = criarGrafo();

    if (grafo == NULL) {
        return 1;
    }

    montarGrafo(grafo);

    exibirGrafo(grafo);

    liberarGrafo(grafo);

    return 0;
}