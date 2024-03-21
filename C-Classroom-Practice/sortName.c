#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char names[1000][100];
    int count = 0;

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fgets(names[count], 100, inputFile) != NULL) {

        names[count][strcspn(names[count], "\n")] = '\0';
        count++;
    }

    fclose(inputFile);

    qsort(names, count, sizeof(names[0]), compareStrings);

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s\n", names[i]);
    }

    fclose(outputFile);

    printf("Names sorted and written to output.txt successfully\n");

    return 0;
}
