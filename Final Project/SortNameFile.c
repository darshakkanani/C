#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

int main(void)
{
    char *strFileName = "input.txt";     // Replace with your input file name
    char *strFileSummary = "output.txt"; // Replace with your output file name
    char strTempData[MAX_LEN];
    char **strData = NULL;
    int noOfLines = 0;

    FILE *ptrFileLog = fopen(strFileName, "r");
    FILE *ptrSummary = fopen(strFileSummary, "w");

    if (ptrFileLog == NULL || ptrSummary == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    // Read and store names in a string list
    while (fgets(strTempData, MAX_LEN, ptrFileLog) != NULL)
    {
        if (strchr(strTempData, '\n'))
            strTempData[strlen(strTempData) - 1] = '\0';

        // Allocate memory for a new string
        char *newString = strdup(strTempData);
        if (newString == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Reallocate memory for the string list
        char **temp = realloc(strData, sizeof(char *) * (noOfLines + 1));
        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
        strData = temp;

        // Assign the new string to the list
        strData[noOfLines] = newString;
        noOfLines++;
    }

    // Bubble sort the names
    for (int i = 0; i < noOfLines - 1; i++)
    {
        for (int j = 0; j < noOfLines - i - 1; j++)
        {
            if (strcmp(strData[j], strData[j + 1]) > 0)
            {
                char *temp = strData[j];
                strData[j] = strData[j + 1];
                strData[j + 1] = temp;
            }
        }
    }

    // Write sorted names to the output file
    for (int i = 0; i < noOfLines; i++)
    {
        fprintf(ptrSummary, "%s\n", strData[i]);
        free(strData[i]);
    }

    free(strData);
    fclose(ptrFileLog);
    fclose(ptrSummary);

    printf("Names sorted and written to %s successfully.\n", strFileSummary);

    return 0;
}
