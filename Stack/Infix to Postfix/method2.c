#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100
int st[MAX];
int top = -1;

void push(int val)
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

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return 0; 
    }
    else
    {
        int val = st[top];
        top--;
        return val;
    }
}

int main()
{
    int value, op1, op2;
    char exp[MAX];
    char *e;
    
    printf("Enter the expression: ");
    fgets(exp, sizeof(exp), stdin);
    
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            push(*e - '0'); 
        }
        else if (*e == '+' || *e == '-' || *e == '*' || *e == '/' || *e == '%')
        {
            op1 = pop();
            op2 = pop();
            switch (*e)
            {
                case '+':
                    value = op2 + op1;
                    break;
                case '-':
                    value = op2 - op1;
                    break;
                case '*':
                    value = op2 * op1;
                    break;
                case '/':
                    if (op1 != 0)
                        value = op2 / op1;
                    else
                    {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    break;
                case '%':
                    if (op1 != 0)
                        value = op2 % op1;
                    else
                    {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    break;
            }
            push(value);
        }
        e++;
    }
    printf("Result: %d\n", pop());
    
    return 0;
}
