#include<stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};

void print(struct node *p)
{
    while(p != NULL)
    {
        printf("%d ",p->value);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one->value = 3;
    two->value = 5;
    three->value = 5;


    two->next = three;
    three->next = NULL;

    head = two;
    print(head);


}