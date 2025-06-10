/* Trabalho 3 - Projeto e Análise de Algoritmos - Subconjuntos Divisíveis
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int N, D;
    scanf("%d", &N);

    while (N != 0) {
        scanf("%d", &D);

        long long int *dp = (long long int *)malloc(D * sizeof(long long int));
        memset(dp, 0, D * sizeof(long long int));
        dp[0] = 1;

        for (int i = 1; i <= N; i++) {

            long long int *novo_dp = (long long int *)malloc((D) * sizeof(long long int));
            memcpy(novo_dp, dp, D * sizeof(long long int));

            for (int j = 0; j < D; j++) {
                int novo_resto = (j + i) % D;
                novo_dp[novo_resto] += dp[j];
            }

            memcpy(dp, novo_dp, D * sizeof(long long int));
            free(novo_dp);
        }

        long long int subconj = dp[0];
        printf("%lld\n", subconj);
        scanf("%d", &N);
        free(dp);
    }

    return 0;
}