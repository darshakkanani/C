#include <stdio.h>

int display(int a)
{
    if (a == 0)
    {
        return 1;
    }
    printf("%d ", a);
    return display(a - 1);
}
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d", &a);

    display(a);
}