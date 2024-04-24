#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode; // The new node becomes the new head
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(struct Node* head, int newData, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    struct Node* temp = head;
    int currentPosition = 1;
    while (temp != NULL && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == NULL || currentPosition > position - 1) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory allocated to the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert nodes at the beginning of the linked list
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("Linked list after insertion at beginning: ");
    printList(head);

    // Insert node at a specific position in the linked list
    insertAtPosition(head, 25, 2);

    printf("Linked list after insertion at position 2: ");
    printList(head);

    // Free the memory allocated to the linked list
    freeList(head);

    return 0;
}
