#include <stdio.h>

void reverseRange(int arr[], int start, int end) {
    int i, j, temp;

    for (i = start, j = end; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 4, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 3, end = 8;

    printf("Original array: ");
    printArray(arr, n);

    reverseRange(arr, start, end);

    printf("Array after reversing elements within range %d and %d: ", start, end);
    printArray(arr, n);

    return 0;
}