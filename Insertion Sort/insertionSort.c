#include <stdio.h>

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
    insertionSort(arr, size);
    print(arr, size);
}
