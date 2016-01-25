#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Create a console application that prints the current date and time.
 */
int main() 
{
    char *months[] = {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December",
    };
    
    // returns  the time as the number of seconds since 
    // the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
    time_t t = time(NULL);

    // converts the calendar time timep to broken-down time representation, 
    // expressed relative to the user's specified timezone.
    struct tm localTime = *localtime(&t);
    
    printf("%02d %s %4d %02d:%02d:%02d\n", 
            localTime.tm_mday,
            months[localTime.tm_mon],
            localTime.tm_year + 1900,
            localTime.tm_hour,
            localTime.tm_min,
            localTime.tm_sec);
    
    return (EXIT_SUCCESS);
}