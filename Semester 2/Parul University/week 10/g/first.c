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

// Function to search for a particular node in the linked list and return it
struct Node* searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp; // Return the node if found
        }
        temp = temp->next;
    }
    return NULL; // Return NULL if the node is not found
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

    printf("Linked list: ");
    printList(head);

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Search for the node with the given data
    struct Node* result = searchNode(head, key);
    if (result != NULL) {
        printf("Element %d found in the list\n", key);
    } else {
        printf("Element %d not found in the list\n", key);
    }

    // Free the memory allocated to the linked list
    freeList(head);

    return 0;
}
