#include<stdio.h>

struct car
{
    char name[20];
};

struct  car scanValue()
{
    struct car n;
    printf("Enter the model name: ");
    scanf("%s",n.name);
    return n;
}
void printValue(struct car n)
{
    printf("Name: %s\n",n.name);
}
int main()
{
    struct car tata;
    scanValue(tata);
    printValue(tata);
}

