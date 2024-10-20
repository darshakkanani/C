#include<stdio.h>
#include<stdlib.h>

int swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[],int size)
{
    int m;
    for(int i = 0; i < size - 1;i++)
    {
        m = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[m] > arr[j])
            {
                m = j;
            }
        }
        swap(&arr[m],&arr[i]);
    }
}

void bubbleSort(int arr[],int size)
{
    for(int i = 0; i < size - 1;i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[m] > arr[j])
            {
                swap(&arr[m],&arr[i]);
            }
        }
        
    }
}

void insertionSort(int arr[],int size)
{
    
}