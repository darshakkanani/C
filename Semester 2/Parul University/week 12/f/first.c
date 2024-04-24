#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to search for a particular node in the circular linked list
bool searchNode(struct Node* head, int key) {
    struct Node* current = head;
    if (head != NULL) {
        do {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        } while (current != head);
    }
    return false;
}

int main() {
    struct Node* head = NULL;

    // Create a circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Circular linked list: ");
    printList(head);

    // Search for a particular node
    int key = 2;
    if (searchNode(head, key)) {
        printf("%d is present in the circular linked list.\n", key);
    } else {
        printf("%d is not present in the circular linked list.\n", key);
    }

    return 0;
}
