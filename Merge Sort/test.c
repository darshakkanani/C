#include <stdio.h>

int merge(int arr[], int s, int e)
{
    int i, j, k;
    int m = (s + e) / 2;
    int len1 = m - s + 1;
    int len2 = e - m;

    int first[len1];
    int second[len2+1];

    for (i = 0; i < len1; i++)
    {
        first[i] = arr[s + i];
    }
    for (j = 0; j < len2; j++)
    {
        second[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = s;
    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
        {
            arr[k++] = first[i++];
        }
        else if (first[i] > second[j])
        {
            arr[k++] = second[j++];
        }
        else
        {
            arr[k++] = second[j++];
        }
    }
    while (i < len1)
    {
        arr[k++] = first[i++];
    }

    while (j < len2)
    {
        arr[k++] = second[j++];
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

void scan(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void print(int arr[], int size)
{
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

    printf("Enter the elements of an array: ");
    int arr[100];

    scan(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("After sorting\n");
    print(arr, size);
}