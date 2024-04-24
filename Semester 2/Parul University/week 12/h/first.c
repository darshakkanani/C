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

// Function to insert a new node at the end of the circular linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        newNode->next = newNode;
        *headRef = newNode;
        return;
    }

    struct Node* last = *headRef;
    while (last->next != *headRef) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = *headRef;
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

// Function to delete the first node of the circular linked list
void deleteAtBeginning(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Circular linked list is empty!\n");
        return;
    }
    
    struct Node* temp = *headRef;
    struct Node* last = *headRef;
    
    // Traverse to the last node
    while (last->next != *headRef) {
        last = last->next;
    }
    
    // Update the next pointer of the last node to skip the first node
    last->next = (*headRef)->next;
    
    // Update the head pointer to point to the second node
    *headRef = (*headRef)->next;
    
    // Free the memory allocated for the first node
    free(temp);
}

int main() {
    struct Node* head = NULL;

    // Create a circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Circular linked list before deletion: ");
    printList(head);

    // Delete the first node
    deleteAtBeginning(&head);

    printf("Circular linked list after deletion: ");
    printList(head);

    return 0;
}
