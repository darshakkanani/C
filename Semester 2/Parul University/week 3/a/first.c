#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

// Function to read a complex number
Complex readComplex() {
    Complex c;
    printf("Enter real part: ");
    scanf("%f", &c.real);
    printf("Enter imaginary part: ");
    scanf("%f", &c.imag);
    return c;
}

int main() {
    Complex c;

    printf("Enter a complex number:\n");
    c = readComplex();

    printf("You entered: %.2f + %.2fi\n", c.real, c.imag);

    return 0;
}
