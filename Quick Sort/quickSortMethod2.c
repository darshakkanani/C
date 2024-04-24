#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = count + s;
    swap(&arr[pivotIndex], &arr[s]);

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(&arr[i++], &arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

void scan(int arr[], int size)
{
    printf("Enter the elements of an Array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
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
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    printf("Enter the elements of an Array: ");
    int arr[100];

    scan(arr, size);
    quickSort(arr, 0, size - 1);
    print(arr, size);
}