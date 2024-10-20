#include <stdio.h>

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

int binarySearch(int st[], int key)
{
    int start = top;
    int end = 0;
    int mid = (start + end) / 2;

    while (end <= start)
    {
        if (key == st[mid])
        {
            return mid;
        }
        else if (key > st[mid])
        {
            end = mid + 1;
        }
        else
        {
            start = mid - 1;
        }
        (start + end) / 2;
    }
    return -1;
}

int main()
{
    int key, opt, val;

    do
    {
        printf("Enter the option: \n");
        printf("1. PUSH\n");
        printf("2. Search\n");
        printf("3. EXIT\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the element in the stack: ");
            scanf("%d", &val);
            push(st, val);
            break;
        case 2:
            printf("Enter the key: ");
            scanf("%d", &key);
            int ans = binarySearch(st, key);
            printf("Key found at %d potision from last\n",ans);
            break;
        }
    } while (opt != 3);
}