#include <stdio.h>
#include <ctype.h>

char st[200];
int top = -1;

void push(char x)
{
    st[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return st[top--];
}

int checkPriority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '^')
    {
        return 3;
    }
    return -1;
}

int main()
{
    // char expression[200];
    char *e, x;
    printf("Enter any expression: ");
    gets(e);
    
    // e = expression;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (top != -1 && checkPriority(st[top]) >= checkPriority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}


