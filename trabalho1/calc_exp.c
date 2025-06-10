/* Trabalho 1 - Projeto e Análise de Algoritmos - Cálculo de Exponencial
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>

double exponencial(double B, unsigned int N)
{
    double result;
    // Caso em que o expoente é nulo
    if (N == 0) {
        return 1;
    }
    // Caso base
    if (N == 1) {
        return B;
    }
    // Passo recursivo
    result = exponencial(B, N/2) * exponencial(B, N/2);
    if (N % 2 == 0) 
        return result;
    else
        return result * B;
}

void imprimeDigitoOrdem(double num)
{
    int i = 0;
    while (num >= 10)
    {
        num = num / 10;
        i++;
    }
    printf("%d %d\n", (int)num, i);
}

int main()
{
    double B, resp;
    unsigned int N;
    scanf("%lf %u", &B, &N);
    resp = exponencial(B, N);
    imprimeDigitoOrdem(resp);
    return 0;
}