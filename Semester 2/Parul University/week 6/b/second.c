#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void findsumOfEvenPositionElements(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        printf("%d ", arr[i] + arr[i + 2]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the integers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    findsumOfEvenPositionElements(arr, n);

    return 0;
}
