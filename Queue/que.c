#include <stdio.h>
#define MAX 10
int queue[MAX];
int rear = -1;
int front = -1;

void insert(int value[], int k)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow");
    }
    else
    {
        if (front == -1)
            front = 0;
        int i;
        for (i = 0; i < k; i++)
        {
            rear++;
            queue[rear] = value[i];
        }
    }
}

void delete(int a, int z)
{
    if (front == -1)
    {
        printf("Queue underflow");
    }
    else
    {
        int i;
        for (i = a; i <= z; i++)
        {
            printf("Deleted element: %d", queue[front]);
            front++;
        }
    }
}

void show()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue: ");
        int i;
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int arr[10];
    int k;
    int i;
    int a;
    int z;
    do
    {
        printf("\n1.Insert \n");
        printf("2.Delete \n");
        printf("3.Show \n");
        printf("4.Exit \n");
        printf("\nEnter your choise: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:

            printf("Enter number of total element: ");
            scanf("%d", &k);
            printf("\nEnter the element: ");
            for (i = 0; i < k; i++)
            {
                scanf("%d", &arr[i]);
            }
            insert(arr, k);
            break;
        case 2:

            printf("First numberof index: ");
            scanf("%d", &a);
            printf("Seconf number of index: ");
            scanf("%d", &z);
            delete (a, z);
            break;
        case 3:
            show();
            break;
        case 4:
            break;
        }
    } while (n != 4);
}
