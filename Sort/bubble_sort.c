#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int *newv(unsigned int n);
void *bubbleSort(int *v, int n);

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

    bubbleSort(v, n);

    printf("\nVetor Ordenado : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }

    free(v);

    return 0;
}

//######## bubble sort #############
void *bubbleSort(int *v, int n)
{
    int aux, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i] < v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
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
