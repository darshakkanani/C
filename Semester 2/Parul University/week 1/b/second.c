#include <stdio.h>
#include <stdlib.h>

int** resizeSubarrays(int** array, int rows, int cols, int newCols) {
    for (int i = 0; i < rows; i++) {
        // Resize each subarray
        array[i] = (int*)realloc(array[i], newCols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        // If increasing size, initialize new elements to 0
        if (newCols > cols) {
            for (int j = cols; j < newCols; j++) {
                array[i][j] = 0;
            }
        }
    }
    return array;
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
    int rows, cols, newCols;
    printf("Enter the number of rows and columns of the 2D array: ");
    scanf("%d %d", &rows, &cols);

    int** array = (int**)malloc(rows * sizeof(int*));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    printf("Enter the new number of columns for each subarray: ");
    scanf("%d", &newCols);

    array = resizeSubarrays(array, rows, cols, newCols);

    print2DArray(array, rows, newCols);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
