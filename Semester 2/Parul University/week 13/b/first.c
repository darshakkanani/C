#include <stdio.h>
#include <stdlib.h>

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

// Function to insert a node before a given node
void insertBeforeNode(struct Node** headRef, struct Node* nextNode, int data) {
    if (*headRef == NULL) {
        printf("Circular linked list is empty!\n");
        return;
    }

    struct Node* current = *headRef;
    struct Node* prev = NULL;

    // Find the previous node
    do {
        if (current->next == nextNode) {
            struct Node* newNode = createNode(data);
            newNode->next = nextNode;
            if (prev == NULL) {
                // Insertion before the head node
                *headRef = newNode;
            } else {
                prev->next = newNode;
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *headRef);

    printf("Node not found!\n");
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
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = head; // Make it circular

    printf("Circular linked list before insertion: ");
    printList(head);

    // Insert 4 before node with data 2
    struct Node* targetNode = head->next;
    insertBeforeNode(&head, targetNode, 4);

    printf("Circular linked list after insertion: ");
    printList(head);

    return 0;
}
