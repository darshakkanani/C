#include <stdio.h>

// Define a macro for calculating the square of a number
#define SQUARE(x) ((x) * (x))

// Define a macro to find the maximum of two numbers
#define MAX(x, y) ((x) > (y) ? (x) : (y))

// Define a macro to print a message
#define PRINT_MESSAGE printf("Hello, this is a preprocessor directive example!\n")

int main() {
    int a = 5, b = 3;
    
    // Using SQUARE macro
    printf("Square of %d is: %d\n", a, SQUARE(a));
    
    // Using MAX macro
    printf("Maximum of %d and %d is: %d\n", a, b, MAX(a, b));
    
    // Using PRINT_MESSAGE macro
    PRINT_MESSAGE;
    
    return 0;
}
