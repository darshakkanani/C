#include <stdio.h>

#define MAX 10
int st[MAX], val, top = -1;

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

int main()
{
    push(st,90);
    push(st,8);
    push(st,3);
    push(st,53);
    push(st,34);
    push(st,90);
    push(st,8);
    push(st,3);
    push(st,53);
    push(st,34);

    printf("---------------Before popped------------\n");
    display(st);

    int ans = pop(st);
    printf("\nPopped element is: %d\n",ans);

    printf("---------------After popped------------\n");
    display(st);
}