#include <stdio.h>
#include <stdlib.h>

int** resizeSubarrays(int** array, int rows, int newRows, int cols) {
    // Allocate memory for new number of rows
    int** newArray = (int**)realloc(array, newRows * sizeof(int*));
    if (newArray == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize new rows
    if (newRows > rows) {
        for (int i = rows; i < newRows; i++) {
            newArray[i] = (int*)malloc(cols * sizeof(int));
            if (newArray[i] == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
            // Initialize new row to zeros
            for (int j = 0; j < cols; j++) {
                newArray[i][j] = 0;
            }
        }
    }

    return newArray;
}

void print2DArray(int** array, int rows, int cols) {
    printf("2D Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, newRows;
    printf("Enter the number of rows and columns of the 2D array: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for the initial array
    int** array = (int**)malloc(rows * sizeof(int*));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        // Initialize array elements
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j + 1;
        }
    }

    printf("Enter the new number of rows of the 2D array: ");
    scanf("%d", &newRows);

    // Resize the number of subarrays
    array = resizeSubarrays(array, rows, newRows, cols);

    print2DArray(array, newRows, cols);

    // Free allocated memory
    for (int i = 0; i < newRows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
