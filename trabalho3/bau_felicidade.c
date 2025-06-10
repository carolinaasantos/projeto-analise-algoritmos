/* Trabalho 3 - Projeto e Análise de Algoritmos - Baú da Felicidade
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define True 1
#define False 0
#define MAX 25000 //(100 * 500)

int main(int argc, char *argv[]) {
    
    int n, soma = 0, melhor_soma = 0, result = 0;

    scanf("%d", &n);
    int *moeda = (int *)malloc(100 * sizeof(int));
    bool *dp = (bool *)malloc((MAX + 1) * sizeof(bool));

    while (n != 0) {

        soma = 0;
        memset(dp, False, (MAX + 1) * sizeof(bool));
        dp[0] = True;

        for (int i = 0; i < n; i++) {
            scanf("%d", &moeda[i]);
            soma += moeda[i];
        }
        for (int i = 0; i < n; i++) {
            int peso_moeda = moeda[i];
            for (int j = soma / 2; j >= peso_moeda; j--) {
                if (dp[j - peso_moeda])
                    dp[j] = True;
            }
        }
        for (int i = soma / 2; i >= 0; i--) {
            if (dp[i]) {
                melhor_soma = i;
                break;
            }
        } 

        result = soma - (2 * melhor_soma);
        printf("%d\n", result);

        scanf("%d", &n);
    }

    free(moeda);
    free(dp);

    return 0;
}