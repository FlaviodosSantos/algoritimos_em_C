#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int *newv(unsigned int n);
void insertionSort(int *vetor, unsigned int n);

//######## MAIN #############
int main(void)
{
    int n = 100;
    int *v = newv(n);

    printf("Vetor desordenado : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }

    insertionSort(v, n);

    printf("\nVetor Ordenado : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }

    free(v);

    return 0;
}

//######## insertion sort #############
void insertionSort(int *vetor, unsigned int n)
{
    int i, j, atual;
    for (i = 1; i < n; i++)
    {
        atual = vetor[i];

        for (j = i - 1; (j >= 0) && (atual < vetor[j]); j--)
        {
            vetor[j + 1] = vetor[j];
        }
        vetor[j + 1] = atual;
    }
}

//######### Gera vetor aleatório ###########
int *newv(unsigned int n)
{

    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        v[i] = rand() % n;

    return v;
}
