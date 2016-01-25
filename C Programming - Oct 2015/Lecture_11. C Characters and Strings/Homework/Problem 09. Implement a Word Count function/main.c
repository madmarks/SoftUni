#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 300

void error(char *);
char *get_line(void);
int wc(const char *, const char);

/*
 * Problem 09. Implement a Word Count function
 * 
 * Implement a function which counts the words in a given input. The function 
 * accepts as parameter the input from which to count the words and the 
 * delimiter separating the words. The declaration could be as follows:
 * 
 * ----------------------------------------------------------------------------
 *                   Input                    |          Output
 * ----------------------------------------------------------------------------
 * wc("Hard Rock, Hallelujah!", ' ');         | 3
 * ----------------------------------------------------------------------------
 * wc("Hard Rock, Hallelujah!", ',');         | 2
 * ----------------------------------------------------------------------------
 * wc("Uncle Sam wants you Man", ' ');        | 5
 * ----------------------------------------------------------------------------
 * wc("Beat the beat!", '!');                 | 2 (An empty string counts as a 
 *                                            |    word as well)
 * ----------------------------------------------------------------------------
 */
int main() 
{
    char *text;
    char delimiter;
    
    printf("Text:");
    if(NULL == (text = get_line()))
    {
        return (EXIT_FAILURE);
    }
    
    printf("Delimiter:");
    scanf("%1c", &delimiter);
    
    printf("\n Output\n");
    printf("%d\n", wc(text, delimiter));
    
    /* Free allocated memory */
    
    free(text);

    return (EXIT_SUCCESS);
}

int wc(const char *input, const char delimiter)
{
    int count = 0;
    const char *ptr = input;
    
    // (An empty string counts as a word as well)
    // if first char is delimiter
    if(*ptr == delimiter)
    {
        count++;
        ptr++;
    }
    
    while(*ptr)
    {
        if(*ptr == delimiter)
        {
            count++;
        }
        ptr++;
    }
    
    // (An empty string counts as a word as well)
    // if last char is delimiter
    if(*ptr == delimiter)
    {
        count++;
    }
    
    return count + 1;
}

void error(char *msg)
{
    if(errno != 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
    }
    perror(msg);
}

char *get_line(void)
{
    errno = 0;    
    char *line = (char *)malloc(BUFFER_LENGTH);
    if(NULL == line)
    {
        error("Error when malloc() in get_line() function.\n");
        return NULL;
    }
    
    size_t i = 0;
    size_t total_length = BUFFER_LENGTH - 1;
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(i >= total_length)
        {
            errno = 0;
            char *newLine = (char *)realloc(line, total_length + BUFFER_LENGTH);
            if(NULL == newLine)
            {
                error("Error when realloc in get_line() function.\n");
                return NULL;
            }
            
            total_length += BUFFER_LENGTH;
            line = newLine;
        }
        
        line[i++] = ch;
    }
    
    line[i] = '\0';
    
    errno = 0;
    char *newLine = (char *)realloc(line, i + 1);
    if(NULL == newLine)
    {
        error("Error when realloc in get_line() function.\n");
        return NULL;
    }
    
    line = newLine;
    
    return line;
}