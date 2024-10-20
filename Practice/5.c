#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int rear = -1;
int front = -1;
int x;

void insert()
{
    if(rear == MAX -1)
    {
        printf("Queue overflow");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        printf("Enter the value: ");
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow");
    }
    else
    {
        x = queue[front];
        front++;
        printf("Deleted value: %d",x);
    }
}

void search()
{
    int found = 0;
    if (front == -1 || front > rear)
    {
        printf("Queue underflow");
    }
    printf("Enter the key: ");
    scanf("%d",&x);
    for(int i = front; i <= rear; i++)
    {
        found = 1;
        if(queue[i] == x)
        {
            printf("Key found at %dth index ",i);
            break;
        }
    }
    if (found != 1)
    {
        printf("Key not found ");
    }
}

void traverse()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow");
    }
    else
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Search\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            traverse();
            break;
        case 4:
            search();
            break;
        case 5:
        printf("Exiting..........");
            exit(0);
        default:
            printf("Invalid choice");
        }
    } while (ch != 5);
}