#include <stdio.h>

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
void scan(int arr[], int size)
{
    printf("Enter the elements of an Array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int size;
    printf("Enter the size of an Array: ");
    scanf("%d", &size);

    int arr[100];

    scan(arr, size);

    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    int ans = linearSearch(arr, size, key);

    if (ans != -1)
    {
        printf("Element %d found at index %d\n", key, ans);
    }
    else
    {
        printf("Element %d not found in the array\n", key);
    }
}