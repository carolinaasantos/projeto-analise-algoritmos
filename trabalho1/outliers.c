/* Trabalho 1 - Projeto e Análise de Algoritmos - Cálculo de Exponencial
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>

int comparacao(const void *x, const void *y) {
    double a = *(double *)x;
    double b = *(double *)y;

    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}
 
int main() {
    int N, S, k, outliers = 0;
    double L, a;

    scanf("%d %d %d %lf", &N, &S, &k, &L);

    double **distancias = (double **)malloc(S * sizeof(double *));

    for (int i = 0; i < S; i++) {
        distancias[i] = (double *)malloc(N * sizeof(double));
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &distancias[i][j]);
        }
    }

    for (int i = 0; i < S; i++) {
        double *distancias_ord = (double *)malloc((N - 1) * sizeof(double));
        int index = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                distancias_ord[index] = distancias[i][j];
                index++;
            }
        }

        qsort(distancias_ord, N - 1, sizeof(double), comparacao);

        if (distancias_ord[k] > L) {
            outliers++;
        }

        free(distancias_ord);
    }

    for (int i = 0; i < S; i++) {
        free(distancias[i]);
    }
    
    free(distancias);

    printf("%d\n", outliers);

    return 0;
}