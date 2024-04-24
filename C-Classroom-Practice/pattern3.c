#include<stdio.h>
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);

    int i = 1;
    int k = 1;
    while(i <= a)
    {
        int j = 1;
        while(j <= i)
        {
            printf("%d",k);
            j++;
            k++;
        }
        i++;
        printf("\n");
    }
}