#include <stdio.h>
#include <math.h>

// Function to calculate (base^exp) % mod
int modular_exponentiation(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;  // Ensure base is within mod range
    printf("Initial Base: %d\n", base);

    while (exp > 0) {
        printf("Current exp: %d, result: %d, base: %d\n", exp, result, base);

        if (exp % 2 == 1) {  // If exp is odd
            result = (result * base) % mod;
            printf("Odd exp -> result updated to: %d\n", result);
        } else {  // If exp is even
            printf("Even exp -> no change in result\n");
        }

        // Directly divide exp by 2
        exp = exp / 2;  // Divide exp by 2 (integer division)
        printf("Exp divided by 2 -> exp updated to: %d\n", exp);
        
        // Square the base
        base = (base * base) % mod;
        printf("Base squared -> base updated to: %d\n", base);
    }

    return result;
}


int main() {
    int p, g; // Prime number (p) and primitive root (g)
    int private_key_A, private_key_B; // Private keys for Alice and Bob
    int public_key_A, public_key_B; // Public keys for Alice and Bob
    int shared_secret_A, shared_secret_B; // Shared secrets

    // Input prime number and primitive root
    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    printf("Enter a primitive root modulo %d (g): ", p);
    scanf("%d", &g);

    // Input private keys for Alice and Bob
    printf("Enter Alice's private key: ");
    scanf("%d", &private_key_A);
    printf("Enter Bob's private key: ");
    scanf("%d", &private_key_B);

    // Calculate public keys for Alice and Bob
    printf("\nCalculating Alice's public key...\n");
    public_key_A = modular_exponentiation(g, private_key_A, p);
    printf("\nAlice's public key: %d\n", public_key_A);

    printf("\nCalculating Bob's public key...\n");
    public_key_B = modular_exponentiation(g, private_key_B, p);
    printf("\nBob's public key: %d\n", public_key_B);

    // Calculate shared secrets
    shared_secret_A = modular_exponentiation(public_key_B, private_key_A, p);
    shared_secret_B = modular_exponentiation(public_key_A, private_key_B, p);

    printf("\nShared secret calculated by Alice: %d", shared_secret_A);
    printf("\nShared secret calculated by Bob: %d\n", shared_secret_B);

    // Verify if the shared secrets match
    if (shared_secret_A == shared_secret_B) {
        printf("\nKey Exchange Successful! Shared Secret: %d\n", shared_secret_A);
    } else {
        printf("\nKey Exchange Failed. Secrets do not match.\n");
    }

    return 0;
}





********************************


#include <stdio.h>
#include <math.h>

// Function to calculate (base^exp) % mod
long long modular_exponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  // Ensure base is within mod range
    printf("Initial Base: %lld\n", base);

    while (exp > 0) {
        printf("Current exp: %lld, result: %lld, base: %lld\n", exp, result, base);

        if (exp % 2 == 1) {  // If exp is odd
            result = (result * base) % mod;
            printf("Odd exp -> result updated to: %lld\n", result);
        }
        
        // Directly divide exp by 2
        exp = exp / 2;  // Divide exp by 2 (integer division)
        
        // Square the base
        base = (base * base) % mod;
        printf("Base squared -> base updated to: %lld\n", base);
    }

    return result;
}

int main() {
    long long p, g; // Prime number (p) and primitive root (g)
    long long private_key_A, private_key_B; // Private keys for Alice and Bob
    long long public_key_A, public_key_B; // Public keys for Alice and Bob
    long long shared_secret_A, shared_secret_B; // Shared secrets

    // Input prime number and primitive root
    printf("Enter a prime number (p): ");
    scanf("%lld", &p);
    printf("Enter a primitive root modulo %lld (g): ", p);
    scanf("%lld", &g);

    // Input private keys for Alice and Bob
    printf("Enter Alice's private key: ");
    scanf("%lld", &private_key_A);
    printf("Enter Bob's private key: ");
    scanf("%lld", &private_key_B);

    // Calculate public keys for Alice and Bob
    printf("\nCalculating Alice's public key...\n");
    public_key_A = modular_exponentiation(g, private_key_A, p);
    printf("\nAlice's public key: %lld\n", public_key_A);

    printf("\nCalculating Bob's public key...\n");
    public_key_B = modular_exponentiation(g, private_key_B, p);
    printf("\nBob's public key: %lld\n", public_key_B);

    // Calculate shared secrets
    shared_secret_A = modular_exponentiation(public_key_B, private_key_A, p);
    shared_secret_B = modular_exponentiation(public_key_A, private_key_B, p);

    printf("\nShared secret calculated by Alice: %lld", shared_secret_A);
    printf("\nShared secret calculated by Bob: %lld\n", shared_secret_B);

    // Verify if the shared secrets match
    if (shared_secret_A == shared_secret_B) {
        printf("\nKey Exchange Successful! Shared Secret: %lld\n", shared_secret_A);
    } else {
        printf("\nKey Exchange Failed. Secrets do not match.\n");
    }

    return 0;
}
