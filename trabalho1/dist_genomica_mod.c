/* Trabalho 1 - Projeto e Análise de Algoritmos - Distância Genômica
Nome: Carolina da Silva Santos
Curso: Engenharia de Computação
*/

#include <stdio.h>
#include <stdlib.h>

long long int merge_count (int arr[], int aux[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long int count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            aux[k++] = arr[i++];
        else {
            aux[k++] = arr[j++];
            count += ((mid - i) + 1);
        }
    }

    while (i <= mid)
        aux[k++] = arr[i++];

    while (j <= right)
        aux[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = aux[i];

    return count;
}

long long int mergesort_count(int arr[], int temp[], int left, int right) {
    int mid;
    long long int count = 0;

    if (left < right) {
        mid = (left + right) / 2;

        count += mergesort_count(arr, temp, left, mid);

        count += mergesort_count(arr, temp, mid + 1, right);

        count += merge_count(arr, temp, left, mid, right);
    }
    
    return count;
}
 
int main() {
    int N;
    long long int count;
    
    scanf("%d", &N);

    int *gen1 = (int *)malloc(N * sizeof(int));
    int *gen2 = (int *)malloc(N * sizeof(int));
    int *mod = (int *)malloc(N * sizeof(int));
    int *aux = (int *)malloc(N * sizeof(int));
    int *index = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &gen1[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &gen2[i]);
    }

    for (int i = 0; i < N; i++) {
        index[gen1[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        mod[i] = index[gen2[i]];
    }

    count = mergesort_count(mod, aux, 0, N-1);

    free(gen1);
    free(gen2);
    free(mod);
    free(aux);
    free(index);

    printf("%lld\n", count);

    return 0;
}
