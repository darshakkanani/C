#include <stdio.h>

// Function to write a complex number
void writeComplex(double real, double imag) {
    printf("Complex Number: %.2f + %.2fi\n", real, imag);
}

int main() {
    // Input real and imaginary parts of the complex number
    double real, imag;
    printf("Enter the real part of the complex number: ");
    scanf("%lf", &real);
    printf("Enter the imaginary part of the complex number: ");
    scanf("%lf", &imag);

    // Call the function to write the complex number
    writeComplex(real, imag);

    return 0;
}
