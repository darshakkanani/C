#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void printRandoms(int data[],int size)
{
    int lower = 1;
    int upper = size;
    for (int i = 0; i < size; i++)
    {
        data[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void insertionSort(int arr[], int size)
{
    int i, j, min_idx;
    for (i = 1; i < size; i++)
    {
        min_idx = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > min_idx; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = min_idx;
    }
}

int main()
{
    int arr[50000];
    int size = 50000;
    printRandoms(arr,size);

    clock_t start = clock();
    insertionSort(arr, size);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %lf\n", time_taken);

    return 0;
}
