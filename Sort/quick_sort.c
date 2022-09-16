#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int *newv(unsigned int n);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], long int low, long int high);

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

    quickSort(v, 0, n - 1);

    printf("\nVetor Ordenado : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }

    free(v);

    return 0;
}

//######## quick sort #############
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{ // low = inicio , high = fim
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], long int low, long int high)
{ // low = inicio , high = fim
    if (low < high)
    {
        long int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
