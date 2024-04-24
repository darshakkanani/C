#include <stdio.h>

#define DEBUG 1 // Define DEBUG to 1 to enable debugging

int main() {
#ifdef DEBUG
    printf("Debugging is enabled!\n");
#else
    printf("Debugging is disabled!\n");
#endif

    return 0;
}
