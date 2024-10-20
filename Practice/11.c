#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right_child;
    struct node *left_child;
};

struct node *new_node(int x)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}

struct node *insert(struct node *root,int x)
{
    if(root == NULL)
    {
        return new_node(x);
    }
    else if(x > root->data)
    {
        root->right_child = insert(root->right_child,x);
    }
    else
    {
        root->left_child = insert(root->left_child,x);
    }
    return root;
}

void pre(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d", root->data);
    pre(root->left_child);
    pre(root->right_child);
}

void in(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    in(root->left_child);
    printf("%d", root->data);
    in(root->right_child);
}

void post(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    post(root->left_child);
    post(root->right_child);
    printf("%d", root->data);
}

int main()
{
    struct node *root = NULL;
    int ch, x;
    do{
        printf("\n1.Create\n2.Preorder\n3.Inorder\n4.Poseorder\n5.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter teh value to insert: ");
                scanf("%d",&x);
                root = insert(root,x);
                printf("Inserted %d into the BST\n",x);
                break;
            case 2:
                pre(root);
                break;
            case 3:
                in(root);
                break;
            case 4:
                post(root);
                break;
            case 5:
                printf("Exiting.......");
                exit(0);
            default:
                printf("Invalid choice");
        }
    }while(ch != 5);
}