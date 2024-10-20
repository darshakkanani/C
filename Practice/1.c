#include <stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX], top = -1;
int x;

void insert()
{
    if (top == MAX - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void delete()
{
    if (top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        x = stack[top];
        top--;
        printf("Deleted value: %d", x);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        printf("Peek value: %d", stack[top]);
    }
}

void search()
{
    int key;
    int found = 0;
    if (top == -1)
    {
        printf("Stack is underflow");
    }
        printf("Enter the key: ");
        scanf("%d", &key);
        for (int i = top; i >= 0; i--)
        {
            found = 1;
            if (stack[i] == key)
            {
                printf("Key found at %dth position", i);
                break;
            }
        }
    if(!found)
    {
        printf("Key not found");
    }
}

void traverse()
{
    if(top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        for(int i = top; i >= 0; i--)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Peek\n4.Search\n5.Traverse\n6.Exit\n");
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
            peek();
            break;
        case 4:
            search();
            break;
        case 5:
            traverse();
            break;
        case 6:
        printf("Exiting..........");
            exit(0);
        default:
            printf("Invalid choice");
        }
    } while (ch != 6);
}