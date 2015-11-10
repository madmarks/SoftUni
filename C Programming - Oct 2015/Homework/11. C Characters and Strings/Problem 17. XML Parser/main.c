#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
_Bool xml_parse(char *, char **, char **);

/*
 * Problem 17. XML Parser
 * 
 * Write a program that reads n lines in XML format and parses their contents. 
 * A line is considered valid if it follows the format <{tag}>{data}</{tag}>. 
 * In case of invalid line format, print "Invalid format".
 * 
 * ----------------------------------------------------------------------------
 *                   Input                   |            Output
 * ----------------------------------------------------------------------------
 * <name>Gosho</name>                        | Name: Gosho
 * <age>13</age>                             | Age: 13
 * <eye-color>blue</eye-color>               | Eye-color: blue
 * ----------------------------------------------------------------------------
 * <nGosho</name>                            | Invalid format
 * <sex>male</sex>                           | Sex: male
 * <height>176cm<height>                     | Invalid format
 * ----------------------------------------------------------------------------
 */
int main() 
{
    int num_lines;
    char * line = NULL;
    size_t line_buf_size = 0;
    
    char * tag_name;
    char * tag_value;
    char buffer[BUFFER_LENGTH];
    
    printf("Number of lines:");
    scanf("%d", &num_lines);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    char **output = (char **)malloc(num_lines * sizeof(char *));
    if(NULL == output)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    size_t i;
    ssize_t len;
    for(i = 0; i < num_lines; i++)
    {
        if(-1 == (len = get_line(&line, &line_buf_size, stdin)))
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }
        
        if(xml_parse(line, &tag_name, &tag_value))
        {
            // A null character is written at the end of 
            // the characters written by sprintf
            
            sprintf(buffer, "%s: %s", tag_name, tag_value);
            
            buffer[0] = toupper(buffer[0]);
            
            output[i] = (char *)malloc(strlen(buffer) + 1);
            if(NULL == output[i])
            {
                error("Error", false);
                return (EXIT_FAILURE);
            }            
            
            strcpy(output[i], buffer);            
        }
        else
        {
            output[i] = (char *)malloc(strlen("Invalid format") + 1);
            if(NULL == output[i])
            {
                error("Error", false);
                return (EXIT_FAILURE);
            }            
            
            strcpy(output[i], "Invalid format");
        }
    }
    
    printf("\n Output\n");
    for(i = 0; i < num_lines; i++)
    {
        printf("%s\n", output[i]);
    }
    
    /* Free allocated memory */
    
    for(i = 0; i < num_lines; i++)
    {
        if(output[i])
            free(output[i]);
    }
    
    if(output)
        free(output);
    
    if(line)
        free(line);
    
    return (EXIT_SUCCESS);
}

void error(char *msg, _Bool output_to_log_file)
{
    if (errno)
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    else
        fprintf(stderr, "%s\n", strerror(errno));
    
    if(output_to_log_file)
    {
        FILE * logfile = fopen("log.txt", "a");
        if(logfile)
        {
            printf("\n---------------------------------------\n");
            if (errno)
                fprintf(logfile, "%s: %s\n", msg, strerror(errno));
            else
                fprintf(logfile, "%s\n", strerror(errno));

            free(logfile);
        }
    }
}

ssize_t get_line(char **lineptr, size_t *buf_size, FILE *stream)
{
    /* Sanity checks. */
    if (lineptr == NULL || buf_size == NULL || stream == NULL)
        return -1;
    
    /* Allocate the line the first time. */
    if (*lineptr == NULL)
    {
        errno = 0;
        *lineptr = (char *)malloc(BUFFER_LENGTH);        
        if(NULL == *lineptr)
        {
            error("Error when malloc() in get_line() function.", false);
            return -1;
        }
        *buf_size = BUFFER_LENGTH;
    }
    
    size_t i = 0;
    char ch;
    while((ch = getc(stream)) != '\n' && ch != EOF)
    {
        if(i == (*buf_size - 1))
        {
            errno = 0;
            char *newLine = (char *)realloc(*lineptr, *buf_size + BUFFER_LENGTH);
            if(NULL == newLine)
            {
                if(*lineptr)
                    free(*lineptr);
                
                error("Error when realloc in get_line() function.", false);
                return -1;
            }
            
            *lineptr = newLine;
            *buf_size += BUFFER_LENGTH;
        }
        
        (*lineptr)[i++] = ch;
    }
    
    (*lineptr)[i] = '\0';
    
    return (ssize_t)(i + 1); 
}

_Bool xml_parse(char * text, char ** tag_name, char ** tag_value)
{
    size_t len = strlen(text);
    
    char * first_symbol_open_tag = strchr(text, '<');
    if(!first_symbol_open_tag) return false;
    
    char * last_symbol_open_tag = strchr(first_symbol_open_tag, '>');
    if(!last_symbol_open_tag) return false;
    
    char * first_symbol_close_tag = strstr(last_symbol_open_tag, "</");
    if(!first_symbol_close_tag) return false;
    
    char * last_symbol_close_tag = strchr(first_symbol_close_tag, '>');
    if(!last_symbol_close_tag) return false;
    
    *last_symbol_open_tag = '\0';
    *first_symbol_close_tag = '\0';    
    *last_symbol_close_tag = '\0';
    
    int len_open_tag = last_symbol_open_tag - (first_symbol_open_tag + 1);
    int len_close_tag = last_symbol_close_tag - (first_symbol_close_tag + 2);
    
    if(len_open_tag <= 0 
            || len_close_tag <= 0 
            || (len_open_tag != len_close_tag))
    {
        return false;
    }
    
    size_t i = 0;
    while(i < len_open_tag)
    {
        if(*(first_symbol_open_tag + 1 + i) != *(first_symbol_close_tag + 2 + i))
        {
            return false;
        }
        
        i++;
    }

    *tag_name = first_symbol_open_tag + 1;
    *tag_value = last_symbol_open_tag + 1;
    
    return true;
}