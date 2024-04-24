#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node after a particular node
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some elements
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    insertAfter(head, 1);
    insertAfter(head, 3);

    // Print the linked list
    printLinkedList(head);

    return 0;
}
