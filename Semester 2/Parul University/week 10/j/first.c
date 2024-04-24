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

// Function to delete the node after a particular node in the linked list
void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("No node to delete after.\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp); // Free the memory of the deleted node
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

    printf("Linked list before deletion: ");
    printList(head);

    // Find the node with data 20
    struct Node* prevNode = head;
    while (prevNode != NULL && prevNode->data != 20) {
        prevNode = prevNode->next;
    }

    // Delete the node after the node with data 20
    deleteAfter(prevNode);

    printf("Linked list after deletion after node with data 20: ");
    printList(head);

    // Free the memory allocated to the linked list
    freeList(head);

    return 0;
}
