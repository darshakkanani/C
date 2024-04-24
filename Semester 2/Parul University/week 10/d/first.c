#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node before a particular node
void insertBeforeNode(struct Node** head, int newData, int key) {
    struct Node *temp = *head, *prev = NULL;
    struct Node* newNode = createNode(newData);

    // If key is found at head node
    if (temp != NULL && temp->data == key) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the linked list until the key is found
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key is not found
    if (temp == NULL) {
        printf("Key not found in the list\n");
        free(newNode);
        return;
    }

    // Insert the new node before the key node
    prev->next = newNode;
    newNode->next = temp;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int newData, key;

    // Creating the linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Linked list before insertion: ");
    printLinkedList(head);

    // Input data to be inserted and the key node
    printf("Enter the data to be inserted: ");
    scanf("%d", &newData);
    printf("Enter the key node data before which the data should be inserted: ");
    scanf("%d", &key);

    // Inserting node before a particular node
    insertBeforeNode(&head, newData, key);

    printf("Linked list after insertion: ");
    printLinkedList(head);

    return 0;
}
