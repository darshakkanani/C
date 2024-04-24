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

// Function to insert a new node at a specific position in the circular linked list
void insertAtPosition(struct Node** headRef, int position, int data) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        if (*headRef == NULL) {
            *headRef = newNode;
            newNode->next = newNode; // Make it circular
        } else {
            newNode->next = (*headRef)->next;
            (*headRef)->next = newNode;
            struct Node* temp = *headRef;
            *headRef = newNode;
            newNode = temp;
        }
    } else {
        struct Node* current = *headRef;
        for (int i = 2; i < position; i++) {
            if (current->next == *headRef) {
                printf("Position is out of range!\n");
                return;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
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

    // Insert a node with value 4 at position 2
    insertAtPosition(&head, 2, 4);

    printf("Circular linked list after insertion: ");
    printList(head);

    return 0;
}
