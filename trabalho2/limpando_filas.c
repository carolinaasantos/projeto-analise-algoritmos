/* Trabalho 2 - Projeto e Análise de Algoritmos - Limpando Filas
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM (1<<24)
static unsigned int vistos[TAM];

void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (i == n-1) 
            printf("%d", v[i]);
        else
            printf("%d ", v[i]);
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

    // crie uma funcao que resolva o problema
    int cont = 0, a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (vistos[v[i]] == 0) {
            vistos[v[i]] = 1;
            a = v[i];
            v[cont] = a;
            print("v[%d] = %d", cont, v[cont]);
            cont += 1;
        }
    }
    
    imprime(v, cont);    

    free(v);

    return 0;
}