#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void addAtStart(struct node **s, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = value;
    temp->next = *s;
    *s = temp;
}

void addAtEnd(struct node **s, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;

    if (*s == NULL)
    {
        *s = temp;
    }
    else
    {
        struct node *c = *s;
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = temp;
    }
}

void addAfterGivenValue(struct node **g, int value, int num)
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    struct node *c = *g;
    while (c != NULL)
    {
        if (c->data == value)
        {
            temp->data = num;
            temp->next = c->next;
            c->next = temp;
            return;
        }
        c = c->next;
    }

    printf("Value %d not found in the list\n", value);
}

void deleteAtStart(struct node **s)
{
    if (*s == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *s;
    *s = (*s)->next;
    free(temp);
}

void deleteAtEnd(struct node **s)
{
    if (*s == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*s)->next == NULL)
    {
        free(*s);
        *s = NULL;
        return;
    }

    struct node *prev = NULL;
    struct node *cur = *s;

    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;
    free(cur);
}

void deleteAfterGivenValue(struct node **g, int value)
{
    if (*g == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    struct node *c = *g;

    while (c != NULL && c->data != value)
    {
        c = c->next;
    }

    if (c == NULL || c->next == NULL)
    {
        printf("Value %d not found in the list or it is the last element\n", value);
        return;
    }

    struct node *temp = c->next;
    c->next = temp->next;
    free(temp);
}

void linearSearch(struct node *l, int value) 
{
    while (l != NULL) 
    {
        if (l->data == value) 
        {
            printf("Found\n");
            return;
        }
        l = l->next;
    }
    printf("Not found\n");
}

void selectionSort(struct node *s)
{
    struct node *ptr;
    struct node *cur;
    struct node *min;

    if (s == NULL || s->next == NULL)
    {
        return;
    }

    for (ptr = s; ptr != NULL; ptr = ptr->next)
    {
        min = ptr;

        for (cur = ptr->next; cur != NULL; cur = cur->next)
        {
            if (cur->data < min->data)
            {
                min = cur;
            }
        }

        if (min != ptr)
        {
            int temp = ptr->data;
            ptr->data = min->data;
            min->data = temp;
        }
    }
}

void bubbleSort(struct node *b)
{
    int swapped;
    struct node *ptr;
    struct node *last = NULL;

    if (b == NULL || b->next == NULL)
    {
        return;
    }

    do
    {
        swapped = 0;
        ptr = b;

        while (ptr->next != last)
        {
            if (ptr->data > ptr->next->data)
            {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

void insertionSort(struct node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct node *sorted = NULL;
    struct node *current = *head;

    while (current != NULL)
    {
        struct node *next = current->next;

        if (sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            struct node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted;
}

void splitList(struct node *source, struct node **front, struct node **back)
{
    struct node *slow;
    struct node *fast;

    if (source == NULL || source->next == NULL)
    {
        *front = source;
        *back = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }
}

struct node *merge(struct node *a, struct node *b)
{
    struct node *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void mergeSort(struct node **head)
{
    struct node *current = *head;
    struct node *a;
    struct node *b;

    if (current == NULL || current->next == NULL)
        return;

    splitList(current, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head = merge(a, b);
}

struct node *getTail(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    while (head->next != NULL)
        head = head->next;

    return head;
}

struct node *partition(struct node *head, struct node *end, struct node **newHead, struct node **newEnd)
{
    struct node *pivot = end;
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *tail = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if (*newHead == NULL)
                *newHead = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            struct node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

struct node *quickSortRecur(struct node *head, struct node *end)
{
    if (!head || head == end)
        return head;

    struct node *newHead = NULL;
    struct node *newEnd = NULL;

    struct node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        struct node *temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(struct node **headRef)
{
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}
int main()
{
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one->data = 9;
    two->data = 5;
    three->data = 5;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    int a, num, b;
    do
    {
        printf("Enter the number\n1 => Print all elements\n2 => Add element at start of the link list\n3 => Add element at last of link list\n4 => Add element after at givern number of link list\n5 => Delete element at start of link list\n6 => Delete element at end of link list\n7 => Delete element at afetr given number of link list\n8 => Search element\n9 => Sort link list\n10 => Exit\n ");
        printf("Enter you choice: ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            print(head);
            break;
        case 2:
            printf("Enter the number: ");
            scanf("%d", &num);
            addAtStart(&head, num);
            print(head);
            break;
        case 3:
            printf("Enter the number: ");
            scanf("%d", &num);
            addAtEnd(&head, num);
            print(head);
            break;
        case 4:
            printf("Enter that number which one do you want to insert: ");
            scanf("%d", &num);
            int value;
            printf("Enter the value: ");
            scanf("%d", &value);
            addAfterGivenValue(&head, value, num);
            print(head);
            break;
        case 5:
            deleteAtStart(&head);
            print(head);
            break;
        case 6:
            deleteAtEnd(&head);
            print(head);
            break;
        case 7:
            printf("Enter the number: ");
            scanf("%d", &num);
            deleteAfterGivenValue(&head, num);
            print(head);
            break;
        case 8:
            printf("Enter the number: ");
            scanf("%d", &num);
            linearSearch(head, num);
            break;
        case 9:
            do
            {
                printf("1 => Selection Sort\n2 => Bubble sort\n3 => Insertion Sort\n4 => Merge Sort\n5 => Quick Sort\n6 => Exit\n");
                printf("Enter you choice: ");
                scanf("%d", &b);
                switch (b)
                {
                case 1:
                    selectionSort(head);
                    print(head);
                    break;
                case 2:
                    bubbleSort(head);
                    break;
                case 3:
                    insertionSort(&head);
                    print(head);
                    break;
                case 4:
                    mergeSort(&head);
                    print(head);
                    break;
                case 5:
                    quickSort(&head);
                    print(head);
                    break;
                case 6:
                    printf("Exiting\n");
                    break;
                }
            } while (b != 6);
        case 10:
            printf("Exiting\n");
            break;
        }
    } while (a != 10);
}