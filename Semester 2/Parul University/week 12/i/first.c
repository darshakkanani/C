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

// Function to delete the last node of the circular linked list
void deleteAtEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Circular linked list is empty!\n");
        return;
    }
    
    struct Node* current = *headRef;
    struct Node* prev = NULL;
    
    // Traverse to the last node
    while (current->next != *headRef) {
        prev = current;
        current = current->next;
    }
    
    // Update the next pointer of the second last node to point to the first node
    if (prev != NULL) {
        prev->next = *headRef;
    }
    
    // If there was only one node, update head to NULL
    if (current == *headRef) {
        *headRef = NULL;
    }
    // Free the memory allocated for the last node
    free(current);
}

int main() {
    struct Node* head = NULL;

    // Create a circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Circular linked list before deletion: ");
    printList(head);

    // Delete the last node
    deleteAtEnd(&head);

    printf("Circular linked list after deletion: ");
    printList(head);

    return 0;
}
