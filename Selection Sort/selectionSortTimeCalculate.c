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

void printRandoms(int lower, int upper, int count)
{
    for (int i = 0; i < count; i++)
    {
        int num = (rand() % (upper - lower + 1)) + lower;
    }
}

void selectionSort(int arr[], int size)
{
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) // Corrected the loop condition
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

int main()
{
    int arr[50000];
    int size = 50000;
    printRandoms(0, 50000, size);

    clock_t start = clock();
    selectionSort(arr, size);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort: %lf\n", time_taken);

    return 0;
}
