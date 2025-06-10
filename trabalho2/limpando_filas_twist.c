/* Trabalho 2 - Projeto e Análise de Algoritmos - Limpando Filas
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM (1<<24)
static unsigned int vistos[TAM];

void imprime(int v[], int cont)
{
    for (int i = cont-1; i >= 0; i--) {
        if (i == 0) 
            printf("%d", v[i]);
        else
            printf("%d ", v[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int n;

    if (argc != 1)
    {
        printf("Numero incorreto de parametros. Ex: .\\nome_arquivo_executavel\n");
        return 0;
    }

    // lendo o tamanho de um vetor e os elementos do mesmo
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // crie uma funcao que resolva o problema
    int cont = 0;
    int *result = (int *)malloc(n * sizeof(int));
    
    for (int i = n-1; i >= 0; i--) {
        if (vistos[v[i]] == 0) {
            vistos[v[i]] = 1;
            result[cont] = v[i];
            cont++;
        }
    }
    
    imprime(result, cont); 

    free(result);
    free(v);

    return 0;
}