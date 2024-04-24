#include <stdio.h>

int display(int a)
{
    int sum;
    if (a == 0)
    {
        return 0;
    }
    sum = a + display(a - 1);
    printf("%d + ", a);
    return sum;
}
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d", &a);

    printf("\b\b = %d\n", display(a));
}