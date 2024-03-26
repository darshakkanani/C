#include<stdio.h>

struct car
{
    char name[20];
};

void scanValue(struct car *t)
{
    printf("Enter the model name: ");
    scanf("%s",t->name);
}
void printValue(struct car *c)
{
    printf("Name: %s\n",c->name);
}
int main()
{
    struct car tata;
    scanValue(&tata);
    printValue(&tata);
}

