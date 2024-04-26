#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

void print(struct ListNode* p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insertionSort(struct ListNode** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct ListNode* sorted = NULL;
    struct ListNode* current = *head;

    while (current != NULL) {
        struct ListNode* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct ListNode* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted;
}

void push(struct ListNode** head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct ListNode* head = NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    printf("Linked List before sorting:\n");
    print(head);

    insertionSort(&head);

    printf("Linked List after sorting:\n");
    print(head);

    return 0;
}
