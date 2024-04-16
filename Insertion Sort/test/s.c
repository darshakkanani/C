#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[],int size)
{
    int i,j,min_index;

    for(i = 0; i < size-1;i++)
    {
        for(j = i+1; j < size; j++)
        {
            min_index = j;
        }
        swap(&arr[min_index], &arr[i]);
    }
}

int print(int arr[],int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[5] = {34,7,5,0,9};

    printf("\n-----------After the sorting--------------\n");
    selectionSort(arr,5);
    print(arr,5);

}