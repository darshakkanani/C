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

int main()
{
    push(st, 67);
    push(st, 9);

    display(st);
}