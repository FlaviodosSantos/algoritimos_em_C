#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

void *merge(int *vetor, int comeco, int meio, int fim);
void *mergeSort(int *vetor, int comeco, int fim);
int *newv(unsigned int n);

int main(void)
{
    int n = 100;
    int *v = newv(n);

    printf("Vetor desordenado : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }

    mergeSort(v, 0, n - 1);

    printf("\nVetor Ordenado : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }

    free(v);

    return 0;
}

void *merge(int *vetor, int comeco, int meio, int fim)
{
    int i = comeco;
    int j = meio + 1, k = 0;

    int *aux = (int *)malloc((fim - comeco + 1) * sizeof(int));

    while (k <= fim - comeco)
    {
        if ((vetor[i] < vetor[j] && i <= meio) || (j > fim))
        {
            aux[k] = vetor[i];
            i++;
        }
        else
        {
            aux[k] = vetor[j];
            j++;
        }
        k++;
    }
    k = 0;

    while (k <= fim - comeco)
    {
        vetor[comeco + k] = aux[k];
        k++;
    }
    free(aux);
}

void *mergeSort(int *vetor, int comeco, int fim)
{
    if (comeco < fim)
    {
        int meio = (fim + comeco) / 2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

//######### Gera vetor aleatório ############
int *newv(unsigned int n)
{

    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        v[i] = rand() % n;

    return v;
}
