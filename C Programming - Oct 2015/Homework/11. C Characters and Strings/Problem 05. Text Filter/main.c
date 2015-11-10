#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 300

void error(char *);
char *get_line(void);
char **string_to_arr_of_strings_by_delimiters(char *, char *, size_t *);
void str_find_and_replace(char *, const char *, const char);

/*
 * Problem 05. Text Filter
 * 
 * Write a program that takes a text and a string of banned words. All words 
 * included in the ban list should be replaced with asterisks "*", equal to 
 * the word's length. The entries in the banlist will be separated by a commaand 
 * space ", ". 
 * 
 * The ban list should be entered on the first input line and the text on the 
 * second input line. 
 * 
 *                  Input                   |               Output
 * ----------------------------------------------------------------------------
 * Linux, Windows                           | I'd just like to interject for a 
 *                                          | moment. What you're referring to 
 * I'd just like to interject for a moment. | as *****, is in fact, GNU/*****, 
 * What you're referring to as Linux, is in | or as I've recently taken to 
 * fact, GNU/Linux, or as I've recently     | calling it, GNU plus ***** 
 * taken to calling it, GNU plus Linux      | Sincerely, a ******* user
 * Sincerely, a Windows user                |
 * ---------------------------------------------------------------------------- 
 */
int main() 
{
    char *banned_words;
    char *text;
    size_t count = 0;
    
    printf("Banned words:");
    if(NULL == (banned_words = get_line()))
    {
        return (EXIT_FAILURE);
    }
    
    printf("\nText:");
    if(NULL == (text = get_line()))
    {
        return (EXIT_FAILURE);
    }
    
    char *delimiters = ", ";
    char **arr_of_banned_words = 
        string_to_arr_of_strings_by_delimiters(banned_words, delimiters, &count);
    if(NULL == arr_of_banned_words)
    {
        return (EXIT_FAILURE);
    }
    
    size_t i;
    for(i = 0; i < count; i++)
    {
        str_find_and_replace(text, arr_of_banned_words[i], '*');
        
        free(arr_of_banned_words[i]);
    }
    free(arr_of_banned_words);
    
    /* Print result */
    
    printf("\n Output\n");
    printf("%s\n", text);
    
    /* Free allocated memory */

    free(text);
    free(banned_words);

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

char **string_to_arr_of_strings_by_delimiters(char *buffer, char *delimiters, 
        size_t *count)
{
    char *ptr = buffer;
    *count = 0;
    
    char *token;
    char *savePtr;
    
    /* get the first token */
    if (NULL != (token = strtok_r(buffer, delimiters, &savePtr)))
    {
        (*count)++;

        /* walk through other tokens */
        while (NULL != (token = strtok_r(NULL, delimiters, &savePtr)))
        {
            (*count)++;
        }
    }
    
    errno = 0;
    char **arr = (char **)malloc(*count * sizeof(char *));
    if(errno != 0)
    {
        error("Not enough memory!");
        return NULL;
    }
    
    int i, len;
    for(i = 0; i < *count; i++)
    {
        // skip delimeters
        while(*ptr != 0 && NULL != strchr(delimiters, *ptr))
        {
            ptr++;
        }
        
        len = strlen(ptr) + 1;
        
        errno = 0;
        arr[i] = (char *)malloc(len);
        if(errno != 0)
        {
            error("Not enough memory!");
            return NULL;
        }
        
        strncpy(arr[i], ptr, len);
               
        ptr += len;
    }
    
    return arr; // must free it in the calling function
}

void str_find_and_replace(char *text, const char *str, const char ch)
{
    size_t j;
    char *ptr = text;
    size_t len = strlen(str);

    while(0 != *ptr && NULL != (ptr = strstr(ptr, str)))
    {
        j = 0;
        while(j < len)
        {
            ptr[j++] = ch;
        }

        ptr += len;
    }
}