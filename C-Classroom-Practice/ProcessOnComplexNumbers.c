#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

struct Complex readC() {
    struct Complex num;
    printf("Enter real part: ");
    scanf("%f", &num.real);
    printf("Enter imaginary part: ");
    scanf("%f", &num.imag);
    return num;
}

void writeC(struct Complex num) {
    printf("%.2f + %.2fi\n", num.real, num.imag);
}

struct Complex addC(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    return sum;
}

struct Complex multC(struct Complex num1, struct Complex num2) {
    struct Complex product;
    product.real = num1.real * num2.real - num1.imag * num2.imag;
    product.imag = num1.real * num2.imag + num1.imag * num2.real;
    return product;
}

int main() {
    struct Complex num1, num2, sum, product;
    printf("Enter the first complex number:\n");
    num1 = readC();
    printf("Enter the second complex number:\n");
    num2 = readC();
    printf("First complex number: ");
    writeC(num1);
    printf("Second complex number: ");
    writeC(num2);
    sum = addC(num1, num2);
    printf("Sum of the two complex numbers: ");
    writeC(sum);
    product = multC(num1, num2);
    printf("Product of the two complex numbers: ");
    writeC(product);
    return 0;
}