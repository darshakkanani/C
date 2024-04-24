#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node after a particular node in the circular doubly linked list
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL!\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

// Function to print the circular doubly linked list starting from a given node
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
    // Create a circular doubly linked list
    struct Node* head = createNode(1);
    head->next = head;
    head->prev = head;

    // Insert nodes
    insertAfterNode(head, 2);
    insertAfterNode(head->next, 3);

    printf("Circular doubly linked list: ");
    printList(head);

    return 0;
}
