#include <stdio.h>

void writeComplex(double real, double imag) {
    printf("Complex Number: %.2f + %.2fi\n", real, imag);
}

int main() {
    
    double real, imag;
    printf("Enter the real part of the complex number: ");
    scanf("%lf", &real);
    printf("Enter the imaginary part of the complex number: ");
    scanf("%lf", &imag);

    writeComplex(real, imag);

    return 0;
}
