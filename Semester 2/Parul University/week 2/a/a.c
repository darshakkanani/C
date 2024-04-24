#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    time_t currentTime;
    struct tm *localTime;

    // Get current time in seconds
    currentTime = time(NULL);

    // Convert the current time to local time
    localTime = localtime(&currentTime);

    // Print the present date and time
    printf("Present Date and Time: %s", asctime(localTime));

    return 0;
}
