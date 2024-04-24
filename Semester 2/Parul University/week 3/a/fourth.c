#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    float real;
    float imag;
};

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return result;
}

int main() {
    struct Complex num1, num2, result;

    // Input for first complex number
    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    // Input for second complex number
    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    // Perform multiplication
    result = multiplyComplex(num1, num2);

    // Display the result
    printf("Result of multiplication: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}
