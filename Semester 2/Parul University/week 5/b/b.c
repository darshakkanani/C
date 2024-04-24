#include <stdio.h>

void reverseRange(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, start, end;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the sorted list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the start and end index of the range to reverse: ");
    scanf("%d %d", &start, &end);

    if (start < 0 || end >= n || start > end) {
        printf("Invalid range!\n");
        return 1;
    }

    reverseRange(arr, start, end);

    printf("List after reversing the range: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
