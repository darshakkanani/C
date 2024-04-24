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

// Function to delete the node before a particular node in the circular linked list
void deleteBeforeNode(struct Node** headRef, struct Node* targetNode) {
    if (*headRef == NULL || targetNode == NULL || targetNode->next == NULL) {
        printf("Invalid node!\n");
        return;
    }

    // If targetNode is the head node, find the last node and update its next pointer
    if (*headRef == targetNode) {
        struct Node* last = *headRef;
        while (last->next != *headRef) {
            last = last->next;
        }
        last->next = (*headRef)->next;
        free(*headRef);
        *headRef = last->next;
        return;
    }

    struct Node* current = *headRef;
    while (current->next != targetNode) {
        current = current->next;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

int main() {
    struct Node* head = NULL;

    // Create a circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Circular linked list before deletion: ");
    printList(head);

    // Delete the node before the third node
    deleteBeforeNode(&head, head->next->next);

    printf("Circular linked list after deletion: ");
    printList(head);

    return 0;
}
