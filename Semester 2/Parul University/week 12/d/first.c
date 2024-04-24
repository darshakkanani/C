#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node before a particular node in the circular linked list
void insertBeforeNode(struct Node** headRef, struct Node* nextNode, int data) {
    if (*headRef == NULL) {
        printf("Circular linked list is empty!\n");
        return;
    }
    
    struct Node* current = *headRef;
    struct Node* prev = NULL;
    
    // Traverse the circular linked list to find the node before the specified position
    do {
        if (current->next == nextNode) {
            struct Node* newNode = createNode(data);
            newNode->next = nextNode;
            current->next = newNode;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *headRef);

    // If the specified node is not found, insert at the end
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    prev->next = newNode;
    *headRef = newNode;
}

// Function to print the circular linked list starting from a given node
void printList(struct Node* head) {
    struct Node* current = head;
    if (head != NULL) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }
}

int main() {
    struct Node* head = NULL;

    // Create a circular linked list with three nodes
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = head; // Make it circular

    printf("Circular linked list before insertion: ");
    printList(head);

    // Insert a node with value 4 before the second node
    insertBeforeNode(&head, head->next, 4);

    printf("Circular linked list after insertion: ");
    printList(head);

    return 0;
}
