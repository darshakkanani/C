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

    struct Node* current = *headRef;
    struct Node* prev = NULL;

    // Traverse until we find the node before the target node
    while (current->next != targetNode) {
        prev = current;
        current = current->next;

        // If we reach the head node again without finding the target node
        if (current == *headRef) {
            printf("Node not found!\n");
            return;
        }
    }

    // If the target node is the head node
    if (prev == NULL) {
        struct Node* last = *headRef;
        while (last->next != *headRef) {
            last = last->next;
        }
        last->next = (*headRef)->next;
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
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

    // Delete the node before the third node
    deleteBeforeNode(&head, head->next->next);

    printf("Circular linked list after deletion: ");
    printList(head);

    return 0;
}
