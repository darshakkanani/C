#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE];

// Function to prepare the Playfair cipher key matrix
void prepareMatrix(char *key) {
    int used[26] = {0};
    used['J' - 'A'] = 1; // Treat 'I' and 'J' as the same letter

/*int used[26] = {0}; // Initialize all to 0

char ch = 'P';       // Let's say we are adding 'P'
int index = ch - 'A'; // 'P' - 'A' = 15
used[index] = 1;     // Mark 'P' as used

// Later check
if (used['P' - 'A'] == 1) {
    printf("'P' has already been added.\n");
}*/


    int index = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (!used[ch - 'A'] && isalpha(ch)) {
            matrix[index / SIZE][index % SIZE] = ch;
            used[ch - 'A'] = 1;

            // Debug print to show matrix status
            printf("Added %c to the matrix at position (%d, %d)\n", ch, index / SIZE, index % SIZE);

            index++;
        }
    }

    // Fill remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[index / SIZE][index % SIZE] = ch;
            used[ch - 'A'] = 1;

            // Debug print to show matrix status
            printf("Added %c to the matrix at position (%d, %d)\n", ch, index / SIZE, index % SIZE);

            index++;
        }
    }
}

// Function to display the key matrix
void displayMatrix() {
    printf("Playfair Cipher Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the position of a character in the matrix
void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Treat 'I' and 'J' as the same

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;

                // Debug print
                printf("Character %c found at position (%d, %d)\n", ch, i, j);

                return;
            }
        }
    }
    // Debug print if character is not found
    printf("Character %c not found in the matrix\n", ch);
}


// Function to decrypt the cipher text
void decryptPlayfair(char *ciphertext, char *plaintext) {
    int len = strlen(ciphertext);

    printf("Decrypting Ciphertext: %s\n", ciphertext);

    for (int i = 0; i < len; i += 2) {
        char a = toupper(ciphertext[i]);
        char b = toupper(ciphertext[i + 1]);

        int row1, col1, row2, col2;
        findPosition(a, &row1, &col1);
        findPosition(b, &row2, &col2);

        printf("Processing pair: %c%c (Positions: [%d,%d] and [%d,%d])\n", a, b, row1, col1, row2, col2);

        if (row1 == row2) { // Same row
            plaintext[i] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            plaintext[i + 1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
            printf("Same Row -> %c%c\n", plaintext[i], plaintext[i + 1]);
        } else if (col1 == col2) { // Same column
            plaintext[i] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            plaintext[i + 1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
            printf("Same Column -> %c%c\n", plaintext[i], plaintext[i + 1]);
        } else { // Rectangle swap
            plaintext[i] = matrix[row1][col2];
            plaintext[i + 1] = matrix[row2][col1];
            printf("Rectangle Swap -> %c%c\n", plaintext[i], plaintext[i + 1]);
        }
    }

    plaintext[len] = '\0'; // Null-terminate the plaintext
    printf("Decrypted Plaintext: %s\n", plaintext);
}

int main() {
    char key[] = "Parul";
    char ciphertext[100];
    char plaintext[100];

    printf("Enter the ciphertext: ");
    scanf("%s", ciphertext);

    prepareMatrix(key);
    displayMatrix();

    decryptPlayfair(ciphertext, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}



*************************************


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE];

// Function to prepare the Playfair cipher key matrix
void prepareMatrix(char *key) {
    int used[26] = {0};
    used['J' - 'A'] = 1; // Treat 'I' and 'J' as the same letter

    int index = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (!used[ch - 'A'] && isalpha(ch)) {
            matrix[index / SIZE][index % SIZE] = ch;
            used[ch - 'A'] = 1;
            index++;
        }
    }

    // Fill remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[index / SIZE][index % SIZE] = ch;
            used[ch - 'A'] = 1;
            index++;
        }
    }
}

// Function to display the key matrix
void displayMatrix() {
    printf("Playfair Cipher Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the position of a character in the matrix
void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Treat 'I' and 'J' as the same
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to decrypt the ciphertext
void decryptPlayfair(char *ciphertext, char *plaintext) {
    int len = strlen(ciphertext);
    int isOdd = len % 2; // Check if length is odd

    // Append 'X' if odd length
    if (isOdd) {
        ciphertext[len] = 'X';
        ciphertext[len + 1] = '\0';
        len++;
    }

    printf("Decrypting Ciphertext: %s\n", ciphertext);

    for (int i = 0; i < len; i += 2) {
        char a = toupper(ciphertext[i]);
        char b = toupper(ciphertext[i + 1]);

        int row1, col1, row2, col2;
        findPosition(a, &row1, &col1);
        findPosition(b, &row2, &col2);

        if (row1 == row2) { // Same row
            plaintext[i] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            plaintext[i + 1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) { // Same column
            plaintext[i] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            plaintext[i + 1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
        } else { // Rectangle swap
            plaintext[i] = matrix[row1][col2];
            plaintext[i + 1] = matrix[row2][col1];
        }
    }

    plaintext[len] = '\0'; // Null-terminate the plaintext

    // Remove appended 'X' if it was added
    if (isOdd && plaintext[len - 1] == 'X') {
        plaintext[len - 1] = '\0';
    }

    printf("Decrypted Plaintext: %s\n", plaintext);
}

int main() {
    char key[] = "Parul";
    char ciphertext[100];
    char plaintext[100];

    printf("Enter the ciphertext: ");
    scanf("%s", ciphertext);

    prepareMatrix(key);
    displayMatrix();

    decryptPlayfair(ciphertext, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}
