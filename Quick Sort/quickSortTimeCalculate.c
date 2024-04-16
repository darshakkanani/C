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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[50000];
    int size = 50000;
    printRandoms(0, 50000, size);

    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort: %lf\n", time_taken);

    return 0;
}
