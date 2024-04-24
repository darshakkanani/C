#include <stdio.h>
// Not Working 
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1; // key not found
}

void scan(int arr[], int size)
{
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[100];

    scan(arr, size);

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    bubbleSort(arr, size);
    int index = binarySearch(arr, size, key);

    if (index != -1)
    {
        printf("Key found at index: %d\n", index);
    }
    else
    {
        printf("Key not found in the array.\n");
    }

    return 0;
}
