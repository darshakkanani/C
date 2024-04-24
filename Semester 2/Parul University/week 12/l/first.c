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

// Function to delete a particular node in the circular linked list
void deleteNode(struct Node** headRef, int key) {
    if (*headRef == NULL) {
        printf("Circular linked list is empty!\n");
        return;
    }

    struct Node* current = *headRef;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (current->data == key) {
        // Find the last node
        struct Node* last = *headRef;
        while (last->next != *headRef) {
            last = last->next;
        }

        // If there is only one node in the list
        if (current->next == *headRef) {
            free(current);
            *headRef = NULL;
            return;
        }

        // Update the next pointer of the last node to skip the head node
        last->next = current->next;
        *headRef = current->next;
        free(current);
        return;
    }

    // Search for the node to be deleted
    do {
        if (current->data == key) {
            break;
        }
        prev = current;
        current = current->next;
    } while (current != *headRef);

    // If the node is not found
    if (current == *headRef) {
        printf("Node with data %d not found in the circular linked list.\n", key);
        return;
    }

    // Update the next pointer of the previous node to skip the current node
    prev->next = current->next;
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

    // Delete the node with data 2
    deleteNode(&head, 2);

    printf("Circular linked list after deletion: ");
    printList(head);

    return 0;
}
