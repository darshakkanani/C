#include<stdio.h>

void move(int n,char source,char dest,char aux)
{
    if(n==1)
    {
        printf("\nmove from %c to %c",source,dest);
    }
    else
    {
        move(n-1,source,aux,dest);
        move(1,source,dest,aux);
        move(n-1,aux,dest,source);
    }
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);

    move(n,'A','C','B');
    return 0;

}