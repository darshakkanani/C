#include<stdio.h>
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);

    int i = 1;
    while(i <= a)
    {
        int j = 1;
        while(j <= i)
        {
            printf("%d",a-i+1);
            j++;
        }
        i++;
        printf("\n");
    }
}