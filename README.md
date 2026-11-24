# GrafoSUS
## Rede de Encaminhamento de Pacientes

Projeto desenvolvido em linguagem C para representar uma rede de encaminhamento de pacientes entre unidades de saúde, utilizando um grafo direcionado e ponderado.

## Funcionalidades

- Representação do grafo por listas de adjacência.
- Busca em profundidade (DFS), com recursão e backtracking.
- Busca em largura (BFS), utilizando fila.
- Escolha interativa da origem e do algoritmo de busca.
- Exibição dos vértices visitados, caminhos e informações da busca.

## Execução

Compile os arquivos do projeto utilizando GCC:

```bash
gcc grafo.c busca.c main.c -o encaminhamento
```

Execute o programa:

**Linux/macOS**
```bash
./encaminhamento
```

**Windows**
```bash
encaminhamento.exe
```

Ao iniciar, utilize o menu interativo para selecionar o algoritmo de busca e o vértice de origem.


### Compilação alternativa com Makefile (opcional)

| Comando | Descrição |
| --- | --- |
| `make` | Compilar o programa |
| `make run` | Compilar e executar |
| `make test` | Executar os testes |
| `make clean` | Remover os executáveis |

## 📍 Integrantes

- João Pinho
- Lorena Eduarda
- Luiz Felipe
