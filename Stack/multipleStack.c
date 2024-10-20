#include <stdio.h>
#include <ctype.h>

#define MAX 10
int st[MAX],topA = -1,topB = MAX;

void pushA(int val)
{
    if (topA == topB)
    {
        printf("Stack Overflow");
    }
    else
    {
        topA++;
        st[topA] = val;
    }
}

int popA()
{
    int val;
    if (topA == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        val = st[topA];
        topA--;
    }
    return val;
}

void displayA()
{
    if (topA == -1)
    {
        printf("Stack Empty");
    }
    else
    {
        for (int i = topA; i >= 0; i--)
        {
            printf("%d ", st[i]);
        }
    }
}

void pushB(int val)
{
    if (topA == topB - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        topA--;
        st[topB] = val;
    }
}

int popB()
{
    int val;
    if (topB == MAX)
    {
        printf("Stack underflow");
    }
    else
    {
        val = st[topA];
        topB++;
    }
    return val;
}

void displayB()
{
    if (topB == MAX)
    {
        printf("Stack Empty");
    }
    else
    {
        for (int i = topB; i <= MAX; i++)
        {
            printf("%d ", st[i]);
        }
    }
}

int main()
{
    int a, val;

    do
    {
        printf("1. PUSH IN STACKA\n2. PUSH IN STACKB\n3. POP IN STACKA\n4. POP IN STACKB\n5.DISPLAY STACKA\n6. DISPLAY STATCKB\n*******************\n");
        printf("Enter the option: ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &val);
            pushA(val);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &val);
            pushB(val);
            break;
        case 3:
            val = popA();
            printf("The value popped from stackA = %d", val);
            break;
        case 4:
            val = popB();
            printf("The value popped from stackB = %d", val);
            break;
        case 5:
            printf("Containt of stackA:");
            displayA();
            break;
        case 6:
            printf("Containt of stackB:");
            displayB();
            break;
        }
    } while (a != 7);
}