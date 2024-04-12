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
        int p = i;
        int j = 1;
        while(j <= i)
        {
            printf("%d",p++);
            j++;
        }
        p = p-2;
        int k = 1;
        while(k <= i-1)
        {
           printf("%d",p--); 
           k++;
        }
        i++;
        printf("\n");
    }
}