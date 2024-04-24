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

// Function to delete the last node of the linked list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    // If there's only one node in the list
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Update the previous node's next pointer
    prev->next = NULL;
    free(temp); // Free the memory of the deleted node
    return head;
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

    // Delete the last node of the linked list
    head = deleteAtEnd(head);

    printf("Linked list after deletion at end: ");
    printList(head);

    // Free the memory allocated to the linked list
    freeList(head);

    return 0;
}
