// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>

// A binary tree node has data, pointer to left child and a pointer to right child
struct node {
	int data;
	struct node* left;
	struct node* right;
};

// Helper function that allocates a new node with the given data and NULL left and right pointers.
struct node* newNode(int data)
{
	struct node* node= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	// First recur on left child
	printInorder(node->left);

	// Then print the data of node
	printf("%d ", node->data);

	// Now recur on right child
	printInorder(node->right);
}

// Given a binary tree, print its nodes in preorder
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
     printf("%d ", node->data);
     printPreorder(node->left);
     printPreorder(node->right);
}
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->data);
}
int main(){
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Inorder traversal of binary tree is \n");
	printInorder(root);
	printf("\nPre order traversal of binary tree is \n");
	printPreorder(root);
	printf("\nPost order traversal of binary tree is \n");
	printPostorder(root);

	getchar();
	return 0;
}

