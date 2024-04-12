#include<stdio.h>

int fact(int a)
{
    if(a==1)
    {
        return 1;
    }
    return a*fact(a-1);
}
int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);

    int ans = fact(a);
    printf("%d\n",ans);
}