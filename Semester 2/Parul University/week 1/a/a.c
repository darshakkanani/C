#include <stdio.h>
#include <stdlib.h>

int* resizeArray(int* array, int size, int newSize) {
    int* newArray = (int*)realloc(array, newSize * sizeof(int));
    if (newArray == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    if (newSize > size) {
        for (int i = size; i < newSize; i++) {
            newArray[i] = 0;
        }
    }

    return newArray;
}

int main() {
    int size, newSize;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the new size of the array: ");
    scanf("%d", &newSize);

    array = resizeArray(array, size, newSize);

    printf("Array after resizing:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
