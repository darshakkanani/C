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

// Function to insert a new node at the beginning of the circular linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *headRef;
    
    // If list is empty, make the new node point to itself
    if (*headRef == NULL) {
        newNode->next = newNode;
    } else {
        // Otherwise, find the last node and adjust pointers
        while (temp->next != *headRef) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *headRef;
    }
    *headRef = newNode; // Update head to point to the new node
}

// Function to print the circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    } else {
        printf("List is empty.\n");
    }
}

int main() {
    struct Node* head = NULL;
    
    // Insert some elements into the circular linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    
    printf("Circular Linked List after insertion at beginning: ");
    printList(head);
    
    return 0;
}
