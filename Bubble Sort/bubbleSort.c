#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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
                swap(&arr[min_idx], &arr[i]);
            }
        }
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
    bubbleSort(arr, size);
    print(arr, size);
}
