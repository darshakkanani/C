#include<stdio.h>
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);

    int i = 1;
    while(i <= a)
    {
        int s = 1;
        while(s <= a-i)
        {
            printf(" ");
            s++;
        }
        int j = 1;
        while(j <= i)
        {
            printf("*");
            j++;
        }
        int k = 1;
        while(k <= i-1)
        {
           printf("*"); 
           k++;
        }
        i++;
        printf("\n");
    }
}