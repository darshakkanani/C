#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printRandoms(int data[],int size)
{
    int lower = 1;
    int upper = size;
    for (int i = 0; i < size; i++)
    {
        data[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void bubbleSort(int arr[], int size)
{
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) // Corrected the loop condition
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                swap(&arr[min_idx], &arr[j]);
            }
        }
    }
}

int main()
{
    int arr[50000];
    int size = 50000;
    printRandoms(arr,size);

    clock_t start = clock();
    bubbleSort(arr, size);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %lf\n", time_taken);

    return 0;
}
