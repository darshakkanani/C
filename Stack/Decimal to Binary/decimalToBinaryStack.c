#include<stdio.h>

#define MAX 10
int st[MAX],top = -1;

void push(int st[],int val)
{
    if(top == MAX-1)
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
    if(top == -1)
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
    int num,digit;
    printf("Enter any decimal number: ");
    scanf("%d",&num);

    while(num > 0)
    {
        digit = num%2;
        push(st,digit);
        num = num/2;
    }
    printf("The binary equivalent is: ");
    while(top != -1)
    {
        printf("%d",pop(st));
    }
    printf("\n");
    return 0;
}