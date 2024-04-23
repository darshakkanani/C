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

    int ele;
    printf("Which element you want to insert enter that element: ");
    scanf("%d", &ele);

    for (int i = size - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = ele;
    size++;
    printf("-----------After Inserting-------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}