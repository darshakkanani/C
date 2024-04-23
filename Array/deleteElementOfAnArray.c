#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of an Array: ");
    scanf("%d", &size);

    int arr[100];
    printf("Enter the element of an Array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    int pos;
    printf("Enter the Position: ");
    scanf("%d", &pos);

    for (int i = pos - 1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    printf("-----------After Deleting-------------\n");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}