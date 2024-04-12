#include <stdio.h>
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d", &a);

    int i = 1;
    while (i <= a)
    {
        int j = 1;
        while (j <= i)
        {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
            j++;
        }
        i++;
        printf("\n");
    }
}