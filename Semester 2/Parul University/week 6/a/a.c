#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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

    int arr[100];
    scan(arr, size);
    int a;
    printf("1 => Insersion Sort\n2 => Quick Sort\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        insertionSort(arr, size);
        print(arr, size);
        break;
    case 2:
        quickSort(arr, 0, size - 1);
        print(arr, size);
        break;
    default:
        printf("Wrong Choice");
        break;
    }
}
