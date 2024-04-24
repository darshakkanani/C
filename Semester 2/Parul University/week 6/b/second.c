#include <stdio.h>
#include <stdlib.h>

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the integers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    bubbleSort(arr, n);

    // Find the sum of every two even position elements
    printf("Sum of every two even position elements: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", arr[i] + arr[i - 1]);
    }
    printf("\n");

    return 0;
}
