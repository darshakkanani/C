#include <stdio.h>
#include <conio.h>
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

int pop(int st[])
{
    int val;
    if (top == -1)
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

void print(int st[])
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", st[i]);
        }
    }
}

void linearSearch(int st[], int key)
{
    int found = 0;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        if (st[i] == key)
        {
            found = 1;
            printf("Key found!\n");
            printf("Position: %d (counting from top)\n", top - i + 1); // Position counting from top
            break;
        }
    }

    if (!found)
    {
        printf("Key not found!\n");
    }
}

int peep(int st[])
{
    if (top == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return (st[top]);
    }
}

int main()
{
    int val, a, n;
    int arr[200];
    do
    {
        printf("\n1. PUSH\n2. POP\n3. PEEP\n4. PRINT\n5. SEARCH\n6. EXIT\n***********************\n");
        printf("Enter your option: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter total elements: ");
            scanf("%d", &n);
            printf("Enter the element for push: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
                push(st, arr[i]);
            }
            break;
        case 2:
            val = pop(st);
            printf("The value deleted from the stack is: %d", val);
            break;
        case 3:
            val = peep(st);
            printf("The top value is: %d", val);
            break;
        case 4:
            printf("Elements: ");
            print(st);
            break;
        case 5:
            printf("Enter the key: ");
            scanf("%d", &val);
            linearSearch(st, val);
            break;
        case 6:
            break;
        default:
            printf("Invalid input");
        }
    } while (a != 6);
}