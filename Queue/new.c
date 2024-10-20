#include <stdio.h>
#define MAX 10

int queue[MAX];
int rear = -1;
int front = -1;

void insert(int value[], int k)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
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
    if (front == -1 || a > z || z > rear)
    {
        printf("Invalid deletion range or queue underflow\n");
    }
    else
    {
        int i;
        for (i = a; i <= z; i++)
        {
            printf("Deleted element: %d\n", queue[front]);
            front++;
        }
    }
}

void show()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
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

int search(int key)
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1; // Return -1 indicating not found
    }

    int i;
    for (i = front; i <= rear; i++)
    {
        if (queue[i] == key)
        {
            printf("Element %d found at index %d\n", key, i);
            return i; // Return index where element is found
        }
    }

    printf("Element %d not found in the queue\n", key);
    return -1; // Return -1 indicating not found
}

int main()
{
    int n;
    int arr[MAX];
    int k;
    int i;
    int a;
    int z;
    int key;

    do
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Show\n");
        printf("4.Search\n");
        printf("5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &k);
            if (k > MAX - (rear - front + 1))
            {
                printf("Not enough space in the queue to insert %d elements\n", k);
                break;
            }
            printf("Enter the elements: ");
            for (i = 0; i < k; i++)
            {
                scanf("%d", &arr[i]);
            }
            insert(arr, k);
            break;
        case 2:
            printf("First index: ");
            scanf("%d", &a);
            printf("Second index: ");
            scanf("%d", &z);
            delete (a, z);
            break;
        case 3:
            show();
            break;
        case 4:
            printf("Enter element to search: ");
            scanf("%d", &key);
            search(key);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (n != 5);

    return 0;
}
