#include <stdio.h>
#include <stdlib.h>

int* resizeArray(int* array, int currentSize, int newSize) {
    int* newArray = (int*)malloc(newSize * sizeof(int));
    
    if (newArray == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Copy elements from the old array to the new array
    int elementsToCopy = currentSize < newSize ? currentSize : newSize;
    for (int i = 0; i < elementsToCopy; i++) {
        newArray[i] = array[i];
    }

    // Free the old array
    free(array);

    return newArray;
}

int main() {
    int size = 5;
    int* array = (int*)malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize array
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int newSize;
    printf("Enter new size of the array: ");
    scanf("%d", &newSize);

    if (newSize < 0) {
        printf("Invalid size\n");
        return 1;
    }

    array = resizeArray(array, size, newSize);

    if (array == NULL) {
        return 1;
    }

    if (newSize > size) {
        for (int i = size; i < newSize; i++) {
            array[i] = i;
        }
    }

    printf("Resized array:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

  
    free(array);

    return 0;
}
