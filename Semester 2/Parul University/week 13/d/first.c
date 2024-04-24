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
        newNode->next = newNode; // Circular link for the first node
        *headRef = newNode;
        return;
    }

    struct Node* current = *headRef;
    // Traverse to the last node
    while (current->next != *headRef) {
        current = current->next;
    }
    // Insert the new node at the end
    current->next = newNode;
    newNode->next = *headRef; // Make it circular
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

// Function to return a particular node in the circular linked list
struct Node* getNode(struct Node* head, int key) {
    struct Node* current = head;
    if (head != NULL) {
        do {
            if (current->data == key) {
                return current;
            }
            current = current->next;
        } while (current != head);
    }
    return NULL; // Node not found
}

int main() {
    struct Node* head = NULL;

    // Create a circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Circular linked list: ");
    printList(head);

    // Return a particular node
    int key = 2;
    struct Node* result = getNode(head, key);
    if (result != NULL) {
        printf("Node with data %d is found at address %p\n", key, result);
    } else {
        printf("Node with data %d is not found in the circular linked list.\n", key);
    }

    return 0;
}
