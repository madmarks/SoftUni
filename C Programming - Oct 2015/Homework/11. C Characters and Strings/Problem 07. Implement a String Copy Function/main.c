#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 300

void error(char *);
char *get_line(void);
char *strncpy_with_buf(char *, const char *, size_t);
char *strncpy_without_buf(const char *, size_t);

/*
 * Problem 07. Implement a String Copy Function
 * 
 * The standard C function strncpy (char *dest, const char *src, size_t n)
 * copies a chunk from the src string to the dest buffer. Try implementing that 
 * function manually. Try doing it without a buffer, by returning a string 
 * created in the body of the function. Does it work? Think why it does or it 
 * doesn't. How can you modify it to work/break it.
 * 
 * ----------------------------------------------------------------------------
 *                     Input                       |          Output
 * ----------------------------------------------------------------------------
 * strncpy(buffer, "SoftUni", 7)                   | SoftUni
 * ---------------------------------------------------------------------------- 
 * strncpy(buffer, "SoftUni", 3)                   | Sof
 * ----------------------------------------------------------------------------
 * strncpy(buffer, "C is cool", 0)                 | (empty string)
 * ----------------------------------------------------------------------------
 * char* result = strncpy("SoftUni", 7)            | ???
 * ----------------------------------------------------------------------------
 */
int main() 
{
    char *src;
    char dest_1[BUFFER_LENGTH];
    char *result;
    
    printf("Input string:");
    if(NULL == (src = get_line()))
    {
        return (EXIT_FAILURE);
    }
    
    printf("\n Output\n");
    
    strncpy_with_buf(dest_1, src, 7);
    printf("%s\n", dest_1);
    
//    strncpy_with_buf(dest_1, src, 3);
//    printf("%s\n", dest_1);
    
//    strncpy_with_buf(dest_1, src, 0);
//    printf("%s\n", dest_1);
   
    if(NULL == (result = strncpy_without_buf(src, 7)))
    {
        return (EXIT_FAILURE);
    }
    printf("%s\n", result);
    
    free(result);
    free(src);

    return (EXIT_SUCCESS);
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

char *strncpy_with_buf(char *dest, const char *src, size_t n)
{
    size_t i;
    for(i = 0; (i < n) && (src[i] != 0); i++)
    {
        dest[i] = src[i];
    }
    
    for( ; i < n; i++)
    {
        dest[i] = '\0';
    }
    
    return dest;
}

char *strncpy_without_buf(const char *src, size_t n)
{
    errno = 0;
    char *dest = (char *)malloc(n + 1);
    if(NULL == dest)
    {
        error("Error when malloc() in strncpy_without_buf() function.\n");
        return NULL;
    }
    
    size_t i;
    for(i = 0; (i < n) && (src[i] != 0); i++)
    {
        dest[i] = src[i];
    }
    
    for( ; i < n; i++)
    {
        dest[i] = '\0';
    }
    
    // caller must clean up memory allocated after the function call
    return dest; 
}