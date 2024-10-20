#include <stdio.h>

#define MAX 10
int st[MAX], val, top = -1;

int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int size)
{
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

void push(int st[], int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

void display(int st[])
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    for (int j = top; j >= 0; j--)
    {
        printf("%d ", st[j]);
    }
}

int main()
{
    int size, opt, val;

    do
    {
        printf("Enter the option: \n");
        printf("1. PUSH\n");
        printf("2. Search\n");
        printf("3. EXIT\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the element in the stack: ");
            scanf("%d", &val);
            push(st, val);
            break;
        case 2:
            printf("Enter the total element you eneterd: ");
            scanf("%d",&size);
            printf("-----------Before the sorting-----------\n");
            display(st);
            selectionSort(st, size);
            printf("\n-----------After the sorting-----------\n");
            display(st);
            break;
        }
    } while (opt != 3);
}