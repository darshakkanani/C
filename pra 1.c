#include <stdio.h>
#include <string.h>

// Encrypt function
void caesar_encrypt(char* plaintext, int key, char* ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = ((ch - 'A' + key) % 26) + 'A';  // Shift character by key
        } else {
            ciphertext[i] = ch;  // Non-alphabet characters remain unchanged
        }
    }
    ciphertext[i] = '\0';  // Null-terminate the ciphertext
}

// Decrypt function
void caesar_decrypt(char* ciphertext, int key, char* decrypted_text) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (ch >= 'A' && ch <= 'Z') {
            decrypted_text[i] = ((ch - 'A' - key + 26) % 26) + 'A';  // Reverse shift by key
        } else {
            decrypted_text[i] = ch;  // Non-alphabet characters remain unchanged
        }
    }
    decrypted_text[i] = '\0';  // Null-terminate the decrypted text
}
void brute_force_attack(char* ciphertext) {
    char decrypted_text[100];
    for (int key = 0; key < 26; key++) {
        caesar_decrypt(ciphertext, key, decrypted_text);
        printf("Key %d: %s\n", key, decrypted_text);
    }
}
int main() {
    char plaintext[100], ciphertext[100], decrypted_text[100];
    int key;

    printf("Enter the plaintext (uppercase letters only): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove newline character from input

    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    // Encrypt the plaintext
    caesar_encrypt(plaintext, key, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);

    // Perform brute-force attack
    printf("\nAttempting brute-force attack...\n");
    brute_force_attack(ciphertext);

    return 0;
}




>>>>>>>>>>>>>>>>>>>>>>>

#include <stdio.h>
#include <string.h>

// Encrypt function
void caesar_encrypt(char* plaintext, int key, char* ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = ((ch - 'A' + key) % 26) + 'A';  // Shift character by key
            printf("Encrypting: plaintext[%d]='%c', ciphertext[%d]='%c'\n", i, ch, i, ciphertext[i]);
        } else {
            ciphertext[i] = ch;  // Non-alphabet characters remain unchanged
        }
    }
    ciphertext[i] = '\0';  // Null-terminate the ciphertext
}

// Decrypt function
void caesar_decrypt(char* ciphertext, int key, char* decrypted_text) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (ch >= 'A' && ch <= 'Z') {
            decrypted_text[i] = ((ch - 'A' - key + 26) % 26) + 'A';  // Reverse shift by key
            printf("Decrypting: ciphertext[%d]='%c', decrypted_text[%d]='%c'\n", i, ch, i, decrypted_text[i]);
        } else {
            decrypted_text[i] = ch;  // Non-alphabet characters remain unchanged
        }
    }
    decrypted_text[i] = '\0';  // Null-terminate the decrypted text
}

// Brute-force attack function
void brute_force_attack(char* ciphertext) {
    char decrypted_text[100];
    for (int key = 0; key < 26; key++) {
        caesar_decrypt(ciphertext, key, decrypted_text);
        printf("Key %d: %s\n", key, decrypted_text);
    }
}

int main() {
    char plaintext[100], ciphertext[100], decrypted_text[100];
    int key;

    printf("Enter the plaintext (uppercase letters only): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    

    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    // Encrypt the plaintext
    caesar_encrypt(plaintext, key, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);

    // Perform brute-force attack
    printf("\nAttempting brute-force attack...\n");
    brute_force_attack(ciphertext);

    return 0;
}
