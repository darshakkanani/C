#include <stdio.h>

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
    printf("1 => Selection Sort\n2 => Bubble Sort\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        selectionSort(arr, size);
        print(arr, size);
        break;
    case 2:
        bubbleSort(arr, size);
        print(arr, size);
        break;
    default:
        printf("Wrong Choice");
        break;
    }
}
