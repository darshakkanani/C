#include <stdio.h>

int digit(int a)
{
    if (a / 10 == 0)
    {
        return a;
    }
    return a % 10 + digit(a / 10);
}
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d", &a);

    int ans = digit(a);
    printf("The sum of digits of %d is %d\n", a, ans);
}