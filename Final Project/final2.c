#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void printRandoms(int data[],int size)
{
    int lower = 1;
    int upper = 50000;

    for (int i = lower; i < upper; i++)
    {
        data[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
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

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
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

void print(int arr[], int size)
{
    printf("------------------After sorting----------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    int arr1[50000];
    int arr2[50000];
    int arr3[50000];
    int arr4[50000];
    int arr5[50000];
    int size = 50000;

    // Generate random numbers for sorting
    printRandoms(arr1, size);
    printRandoms(arr2, size);
    printRandoms(arr3, size);
    printRandoms(arr4, size);
    printRandoms(arr5, size);
    

    clock_t start1 = clock();
    selectionSort(arr1, size);
    clock_t end1 = clock();
    double time_taken1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Selection Sort: %lf seconds\n", time_taken1);

    clock_t start2 = clock();
    bubbleSort(arr2, size);
    clock_t end2 = clock();
    double time_taken2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %lf seconds\n", time_taken2);

    clock_t start3 = clock();
    insertionSort(arr3, size);
    clock_t end3 = clock();
    double time_taken3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %lf seconds\n", time_taken3);

    clock_t start4 = clock();
    mergeSort(arr4, 0, size - 1);
    clock_t end4 = clock();
    double time_taken4 = (double)(end4 - start4) / CLOCKS_PER_SEC;
    printf("Merge Sort: %lf seconds\n", time_taken4);

    clock_t start5 = clock();
    quickSort(arr5, 0, size - 1);
    clock_t end5 = clock();
    double time_taken5 = (double)(end5 - start5) / CLOCKS_PER_SEC;
    printf("Quick Sort: %lf seconds\n", time_taken5);

    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void printRandoms(int lower, int upper, int count)
{
    lower = 0;
    upper = 50000;
    count = 50000;
    for (int i = 0; i < count; i++)
    {
        int num = (rand() % (upper - lower + 1)) + lower;
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int size)
{
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++)
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

void bubbleSort(int arr[], int size)
{
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++)
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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;

    j = 0;

    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
    int arr1[50000];
    int arr2[50000];
    int arr3[50000];
    int arr4[50000];
    int arr5[50000];
    int size = 50000;

    printRandoms(0, 50000, size);

    clock_t start1 = clock();
    selectionSort(arr1, size);
    clock_t end1 = clock();
    double time_taken1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Selection Sort: %lf\n", time_taken1);

    clock_t start2 = clock();
    bubbleSort(arr2, size);
    clock_t end2 = clock();
    double time_taken2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %lf\n", time_taken2);

    clock_t start3 = clock();
    insertionSort(arr3, size);
    clock_t end3 = clock();
    double time_taken3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %lf\n", time_taken3);

    clock_t start4 = clock();
    mergeSort(arr4, 0, size - 1);
    clock_t end4 = clock();
    double time_taken4 = (double)(end4 - start4) / CLOCKS_PER_SEC;
    printf("Merge Sort: %lf\n", time_taken4);

    clock_t start5 = clock();
    quickSort(arr5, 0, size - 1);
    clock_t end5 = clock();
    double time_taken5 = (double)(end5 - start5) / CLOCKS_PER_SEC;
    printf("Quick Sort: %lf\n", time_taken5);

    return 0;
}
*/