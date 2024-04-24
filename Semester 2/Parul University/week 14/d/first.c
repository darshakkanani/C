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

// Function to return a particular node with a given data in the circular doubly linked list
struct Node* returnNode(struct Node* head, int searchData) {
    struct Node* current = head;
    if (head != NULL) {
        do {
            if (current->data == searchData) {
                return current;
            }
            current = current->next;
        } while (current != head);
    }
    return NULL; // Node not found
}

// Function to print the circular doubly linked list starting from the head node
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
    struct Node* head = NULL;

    // Create a circular doubly linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = head;
    head->next->next->next->prev = head->next->next;

    printf("Circular doubly linked list: ");
    printList(head);

    // Return node with data 2
    int searchData = 2;
    struct Node* foundNode = returnNode(head, searchData);
    if (foundNode != NULL) {
        printf("Node with data %d found!\n", searchData);
    } else {
        printf("Node with data %d not found!\n", searchData);
    }

    return 0;
}
