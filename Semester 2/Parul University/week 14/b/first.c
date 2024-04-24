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

// Function to insert a new node before a particular node in the circular doubly linked list
void insertBeforeNode(struct Node** headRef, int data, struct Node* targetNode) {
    if (*headRef == NULL) {
        printf("Circular doubly linked list is empty!\n");
        return;
    }

    struct Node* newNode = createNode(data);

    // If the target node is the head node
    if (*headRef == targetNode) {
        newNode->next = targetNode;
        newNode->prev = targetNode->prev;
        targetNode->prev->next = newNode;
        targetNode->prev = newNode;
        *headRef = newNode;
        return;
    }

    // Traverse until we find the target node
    struct Node* current = *headRef;
    while (current != NULL && current != targetNode) {
        current = current->next;
    }

    // If the target node is not found
    if (current == NULL) {
        printf("Target node not found!\n");
        free(newNode);
        return;
    }

    // Update the pointers to insert the new node before the target node
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

// Function to print the circular doubly linked list starting from the head node
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

    // Create a circular doubly linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = head;
    head->next->next->next->prev = head->next->next;

    printf("Circular doubly linked list before insertion: ");
    printList(head);

    // Insert 5 before the second node
    insertBeforeNode(&head, 5, head->next);

    printf("Circular doubly linked list after insertion: ");
    printList(head);

    return 0;
}
