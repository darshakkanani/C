#include<stdio.h>

#define MAX 10
int st[MAX],val,top = -1;

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

    int ans = peep(st);
    printf("Top element is: %d",ans);
}