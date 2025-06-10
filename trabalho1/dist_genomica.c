/* Trabalho 1 - Projeto e Análise de Algoritmos - Distância Genômica
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>

int count = 0;
 
int main() {
    int N, dist, aux;
    
    scanf("%d", &N);

    int *gen1 = (int *)malloc(N * sizeof(int));
    int *gen2 = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &gen1[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &gen2[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (gen1[i] == gen2[j]) {
                for (int k = j; k > i; k--) {
                    aux = gen2[k];
                    gen2[k] = gen2[k-1];
                    gen2[k-1] = aux;
                    count++;
                }
            }
        }
    }

    free(gen1);
    free(gen2);

    printf("%d\n", count);

    return 0;
}