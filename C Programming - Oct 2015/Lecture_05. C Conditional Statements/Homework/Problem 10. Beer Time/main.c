#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER_LENGTH 50

/*
 * Problem 10. Beer Time
 * 
 * A beer time is after 1:00 PM and before 3:00 AM. Write a program that 
 * enters a time in format "hh:mm tt" (an hour in range [01...12], a minute in 
 * range [00 ... 59] and AM / PM designator) and prints "beer time" or 
 * "non-beer time" according to the definition above or "invalid time" if 
 * the time cannot be parsed. Note that you may need to learn how to parse 
 * dates and times. 
 */
int main() 
{
    char buffer[BUFFER_LENGTH];
    
    printf("Input time: ");    
    fgets(buffer, BUFFER_LENGTH, stdin);
    
    int length = strlen(buffer);
    if(buffer[length - 1] == '\n')
        buffer[length - 1] = '\0';
    
    struct tm time_details;
    
    // Clear the time_details structure.
    memset(&time_details, '\0', sizeof (time_details));
    
    /*
     * char * strptime (const char *s, const char *fmt, struct tm *time_details)
     * 
     * The strptime function parses the input string s according to the format
     * string fmt and stores its results in the structure tp
     */
    if (NULL == strptime(buffer, "%l:%M %p", &time_details))
    {
        // Format string does not match.
        printf("invalid time\n");
        return (EXIT_FAILURE);
    }
    
    int time = time_details.tm_hour * 60 + time_details.tm_min;
    
    int startBeerTime = 13 * 60;
    int endBeerTime = 3 * 60;
    
    _Bool isBeerTime = time >= startBeerTime || time < endBeerTime;
    
    printf("|   time   |     result    |\n");
    if(isBeerTime)
    {
        printf("| %8s |   beer time   |\n", buffer);
    }
    else
    {
        printf("| %8s | non-beer time |\n", buffer);
    }
    
    return (EXIT_SUCCESS);
}

