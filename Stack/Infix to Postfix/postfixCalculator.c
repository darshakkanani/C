#include<stdio.h>
#include<ctype.h>

#define MAX 100
int st[MAX];
int top = -1;

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
    int val = -1;
    if(top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        val = st[top];
        top--;
    }
    return val;
}

int evaluatePostFixExp(char exp[])
{
    int i = 0;
    int op1,op2,value;

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(st,(int)(exp[i])-'0');
        }
        else
        {
            op1 = pop(st);
            op2 = pop(st);
            switch(exp[i])
            {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op2 - op1;
                    break;
                case '*':
                    value = op2 * op1;
                    break;
                case '/':
                    value = op2 / op1;
                    break;
                case '%':
                    value = (int)op2 % (int)op1;
                    break;
            }
            push(st,value);
        }
        i++;
    }
    return pop((st));
}

int main()
{
    int val;
    char exp[200];

    printf("Enter any postfix expression: ");
    gets(exp);

    val = evaluatePostFixExp(exp);
    printf("\nValue of the postfix expression = %d",val);

    return 0;
}