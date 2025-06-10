/* Trabalho 2 - Projeto e Análise de Algoritmos - Black Friday
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(long long int *)a - *(long long int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int prod = n - 3;
    long long int *v = (long long int *)malloc(n * sizeof(long long int));

    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);
    
    qsort(v, n, sizeof(long long int), compara);

    long long int descont = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i == prod) {
            descont += v[i];
            prod -= 3;
        }
    }

    printf("%lld\n", descont);

    free(v);

    return 0;
}
