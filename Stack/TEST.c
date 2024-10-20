/*
#include<stdio.h>
#include<ctype.h>

char stack[20];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop() {
    if(top == -1)
    return -1;
    else
    return stack[top--];
}

int checkpriority(char x){
    if(x == '(')
    return 0;
    if(x == '+' || x == '-')
    return 1;
    if(x == '/' || x == '*')
    return 2;
    if(x == '^')
    return 3;
    return -1;
}

int main(){
    char expression[100];
    char *e, x;
    printf("Please enter any expression: ");
    scanf("%s", expression);
    e = expression;
    printf("Postfix expression: ");
    while(*e != '\0'){
        if(isalnum(*e)){
            printf("%c", *e);
        }
        else if (*e == '('){
            push(*e);
        }
        else if(*e == ')'){
            while((x = pop()) != '(')
            printf("%c", x);
        }
        else {
            while(top != -1 && checkpriority(stack[top]) >= checkpriority(*e))
            printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while(top != -1) {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}
*/

/*
#include <stdio.h>
int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek()
{
    return stack[top];
}

int pop()
{
    int data;
    if (!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data)
{
    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

int main()
{
    push(44);
    push(10);
    push(62);
    push(123);
    push(15);
    printf("Element at top of the stack: %d\n", peek());
    printf("Elements: \n");

    // print stack data
    while (!isempty())
    {
        int data = pop();
        printf("%d\n", data);
    }
    printf("Stack full: %s\n", isfull() ? "true" : "false");
    printf("Stack empty: %s\n", isempty() ? "true" : "false");
    return 0;
}
*/

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

void display(int st[])
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int j = top; j >= 0; j--)
        {
            printf("%d ", st[j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[3] = {2, 4, 2};
    
    push(st, 67);
    push(st, 9);
    // Pushing array elements
    for (int i = 0; i < 3; i++)
    {
        push(st, arr[i]);
    }

    display(st);
    
    return 0;
}

*/