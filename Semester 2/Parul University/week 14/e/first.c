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

// Function to insert a new node at the end of the circular doubly linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *headRef = newNode;
        return;
    }

    struct Node* last = (*headRef)->prev;
    newNode->next = *headRef;
    newNode->prev = last;
    last->next = newNode;
    (*headRef)->prev = newNode;
}

// Function to delete the node before a particular node in the circular doubly linked list
void deleteBeforeNode(struct Node** headRef, struct Node* targetNode) {
    if (*headRef == NULL || targetNode == NULL) {
        printf("Invalid node!\n");
        return;
    }

    struct Node* current = *headRef;
    while (current != NULL && current->next != targetNode) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Target node not found!\n");
        return;
    }

    // If the target node is the head node
    if (current == *headRef) {
        *headRef = (*headRef)->next;
    }

    // If the node to be deleted is the last node
    if (current->prev == *headRef) {
        printf("No node exists before the target node to delete!\n");
        return;
    }

    struct Node* prevNode = current->prev;
    prevNode->prev->next = current;
    current->prev = prevNode->prev;
    free(prevNode);
}

// Function to print the circular doubly linked list starting from the head node
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Circular doubly linked list is empty!\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create a circular doubly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Circular doubly linked list before deletion: ");
    printList(head);

    // Delete the node before the third node
    deleteBeforeNode(&head, head->next->next);

    printf("Circular doubly linked list after deletion: ");
    printList(head);

    return 0;
}
