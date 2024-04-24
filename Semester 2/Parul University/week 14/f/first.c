#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the circular doubly linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *headRef = newNode;
        return;
    }

    struct Node* last = (*headRef)->prev;
    newNode->next = *headRef;
    newNode->prev = last;
    last->next = newNode;
    (*headRef)->prev = newNode;
}

// Function to delete a particular node in the circular doubly linked list
void deleteNode(struct Node** headRef, struct Node* delNode) {
    if (*headRef == NULL || delNode == NULL) {
        printf("Invalid node!\n");
        return;
    }

    // If the list has only one node
    if ((*headRef)->next == *headRef && delNode == *headRef) {
        free(*headRef);
        *headRef = NULL;
        return;
    }

    // If the node to delete is the head node
    if (delNode == *headRef) {
        struct Node* last = (*headRef)->prev;
        *headRef = (*headRef)->next;
        last->next = *headRef;
        (*headRef)->prev = last;
        free(delNode);
        return;
    }

    // If the node to delete is not the head node
    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
    free(delNode);
}

// Function to print the circular doubly linked list starting from the head node
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Circular doubly linked list is empty!\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create a circular doubly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Circular doubly linked list before deletion: ");
    printList(head);

    // Delete the node with data 2
    struct Node* delNode = head->next;
    deleteNode(&head, delNode);

    printf("Circular doubly linked list after deletion: ");
    printList(head);

    return 0;
}
