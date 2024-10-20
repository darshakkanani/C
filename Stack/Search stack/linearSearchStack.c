#include <stdio.h>

#define MAX 10
int st[MAX], top = -1;

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

void linearSearch(int st[], int key)
{
    // int cnt;
    printf("value of top: %d",top);

    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            if (st[i] == key)
            {
                printf("Key found! \n");
                printf("Starting position: %d\n", top - i);
                printf("Ending position: %d\n", i);
                break;
            }
            else
            {
                printf("Key not found!");
                // cnt++;
            }
        }
    }
}

int main()
{
    int key, opt, val;

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
            push(st,val);
            break;
        case 2:
            printf("Enter the key: ");
            scanf("%d",&key);
            linearSearch(st, key);
            break;
        }
    } while (opt != 3);
}

/*
#include <stdio.h>

#define MAX 10
int st[MAX], top = -1;

void push(int st[], int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

int linearSearch(int st[], int key)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int found = 0;
        for (int i = top; i >= 0; i--)
        {
            if (st[i] == key)
            {
                found = 1;
                printf("Key found! Starting position: %d, Ending position: %d\n", i, top - i);
                break;
            }
        }
        if (!found)
        {
            printf("Key not found!\n");
        }
        return found;
    }
}

int main()
{
    int opt, val, key;

    do
    {
        printf("\nEnter the option:\n");
        printf("1. PUSH\n");
        printf("2. Search\n");
        printf("3. EXIT\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            if (top == MAX - 1)
            {
                printf("Stack is full. Cannot push.\n");
            }
            else
            {
                printf("Enter the element to push: ");
                scanf("%d", &val);
                push(st, val);
            }
            break;

        case 2:
            if (top == -1)
            {
                printf("Stack is empty. Cannot search.\n");
            }
            else
            {
                printf("Enter the key to search: ");
                scanf("%d", &key);
                linearSearch(st, key);
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (opt != 3);

    return 0;
}

*/