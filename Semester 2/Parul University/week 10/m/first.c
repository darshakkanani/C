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

// Function to delete a node at a specific position in the linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* temp = head;

    // If the node to be deleted is the head node
    if (position == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Traverse to the node just before the position to be deleted
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    // Delete the node at the given position
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete); // Free the memory of the deleted node

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

    int position;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &position);

    // Delete the node at the specified position
    head = deleteAtPosition(head, position);

    printf("Linked list after deletion: ");
    printList(head);

    // Free the memory allocated to the linked list
    freeList(head);

    return 0;
}
