#include<stdio.h>

int sum(int a)
{
    if(a==1)
    {
        return 1;
    }
    return a+sum(a-1);
}
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);

    int ans = sum(a);
    printf("%d\n",ans);
}