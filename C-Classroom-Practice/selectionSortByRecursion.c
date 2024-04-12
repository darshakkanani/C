#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int minIndex(int a[], int i, int j)
{
    if (i == j)
    {
        return i;
    }
    int k = minIndex(a, i + 1, j);
    if (a[i] < a[k])
    {
        return i;
    }
    else
    {
        return k;
    }
}

void SelectionSort(int a[], int n, int index)
{
    if (index == n)
        return;
    int k = minIndex(a, index, n - 1);
    if (k != index)
        swap(&a[k], &a[index]);
    SelectionSort(a, n, index + 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void scanArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int size;
    printf("Enter the size of an Array: ");
    scanf("%d",&size);

    int arr[100];
    printf("Enter the elements of an Array: ");
    scanArray(arr,size);

    SelectionSort(arr, size, 0);

    printf("---------After Sorting---------\n");
    printArray(arr, size);

    return 0;
}