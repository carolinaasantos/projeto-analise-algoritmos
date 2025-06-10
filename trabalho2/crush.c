/* Trabalho 2 - Projeto e Análise de Algoritmos - Crush
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int destino;
    int peso;
    int proximo;
} Aresta;

typedef struct {
    int dist;
    int vertice;
} node;

static node* heap;
static int tamHeap = 0;

void inserir_no_heap(int dist, int vertice) {
    int indice = ++tamHeap;
    heap[indice].dist = dist;
    heap[indice].vertice = vertice;
    while (indice > 1 && heap[indice].dist < heap[indice / 2].dist) {
        node temp = heap[indice];
        heap[indice] = heap[indice / 2];
        heap[indice / 2] = temp;
        indice /= 2;
    }
}

node remover_do_heap() {
    node topo = heap[1];
    heap[1] = heap[tamHeap--];
    int indice = 1;
    while (1) {
        int menor = indice;
        int esq = 2 * indice;
        int dir = esq + 1;
        if (esq <= tamHeap && heap[esq].dist < heap[menor].dist)
            menor = esq;
        if (dir <= tamHeap && heap[dir].dist < heap[menor].dist)
            menor = dir;
        if (menor == indice)
            break;
        node temp = heap[indice];
        heap[indice] = heap[menor];
        heap[menor] = temp;
        indice = menor;
    }
    return topo;
}

int main() {
    int qntdVertices, qntdArestas;
    scanf("%d %d", &qntdVertices, &qntdArestas);

    Aresta* arestas = malloc(sizeof(Aresta) * qntdArestas);
    int* cabeca = malloc(sizeof(int) * qntdVertices);
    for (int v = 0; v < qntdVertices; v++)
        cabeca[v] = -1;

    for (int i = 0; i < qntdArestas; i++) {
        int origem, destino, peso;
        scanf("%d %d %d", &origem, &destino, &peso);
        arestas[i].destino = destino;
        arestas[i].peso = peso;
        arestas[i].proximo = cabeca[origem];
        cabeca[origem] = i;
    }

    int* menorDistancia = malloc(sizeof(int) * qntdVertices);
    for (int v = 0; v < qntdVertices; v++)
        menorDistancia[v] = INT_MAX;
    menorDistancia[0] = 0;

    heap = malloc(sizeof(node) * (qntdArestas + 1));
    inserir_no_heap(0, 0);

    while (tamHeap) {
        node atual = remover_do_heap();
        int u = atual.vertice;
        int distAtual = atual.dist;
        if (distAtual != menorDistancia[u])
            continue;
        if (u == qntdVertices - 1)
            break;
        for (int indiceAresta = cabeca[u]; indiceAresta != -1; indiceAresta = arestas[indiceAresta].proximo) {
            int vizinho = arestas[indiceAresta].destino;
            int novaDist = distAtual + arestas[indiceAresta].peso;
            if (novaDist < menorDistancia[vizinho]) {
                menorDistancia[vizinho] = novaDist;
                inserir_no_heap(novaDist, vizinho);
            }
        }
    }

    printf("%d\n", menorDistancia[qntdVertices - 1]);

    free(arestas);
    free(cabeca);
    free(menorDistancia);
    free(heap);

    return 0;
}
