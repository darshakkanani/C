#include <stdio.h>

void reverseRange(int arr[], int start, int end) 
{
    // int arr[6];
    // for(int i = start; i <= end; i++)
    // {
    //     scanf("%d",arr[i]);
    // }

    int temp=9;
    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {9,1,2,4,3,4,6,7,8,10};
    // int n = sizeof(arr) / sizeof(arr[0]);
    int start = 3, end = 8;

    printf("Original array: ");
    printArray(arr, 10);

    reverseRange(arr, start, end);

    printf("Array after reversing elements inside the range of %d and %d: ", start, end);
    printArray(arr, 10);

    return 0;
}