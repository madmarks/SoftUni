#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define BUFFER_LENGTH 200

void error(const char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
unsigned int get_sum_of_the_symbols(char *, ssize_t);
char * decimal_to_any_base(const uint64_t, const uint8_t);

/*
 * 
 */
int main(int argc, char** argv) 
{
    int base;
    scanf("%2d", &base);
    
    int c;
    // flush stdin
    while ((c = getchar()) != '\n' && c != EOF);
    
    char * msg = NULL;
    size_t msg_buf_size;
    ssize_t msg_len;
    
    if(-1 == (msg_len = get_line(&msg, &msg_buf_size, stdin)))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    unsigned int sum_of_the_symbols = get_sum_of_the_symbols(msg, msg_len);
    
    char * partially_decrypted_message = 
        decimal_to_any_base(sum_of_the_symbols, base);
    if(NULL == partially_decrypted_message)
    {
        return -1;
    }
    
    /* Print output */
    
    printf("%d%d%s", base, (int)msg_len, partially_decrypted_message);
    
    /* Free allocated resources */
    
    if(partially_decrypted_message)
        free(partially_decrypted_message);
    
    if(msg)
        free(msg);

    return (EXIT_SUCCESS);
}

void error(const char *msg, _Bool output_to_log_file)
{
    if (errno)
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    else
        fprintf(stderr, "%s\n", msg);
    
    if(output_to_log_file)
    {
        FILE * logfile = fopen("log.txt", "a");
        if(logfile)
        {
            printf("\n---------------------------------------\n");
            if (errno)
                fprintf(logfile, "%s: %s\n", msg, strerror(errno));
            else
                fprintf(logfile, "%s\n", msg);

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
    
    return (ssize_t)i; 
}

unsigned int get_sum_of_the_symbols(char * msg, ssize_t msg_len)
{
    unsigned int result = 0;
    
    size_t i;
    for(i = 0; i < msg_len; i++)
    {
        if(isalpha(msg[i]))
        {
            result += (unsigned int)(tolower(msg[i]) - 96);
        }
        else
        {
            result += (unsigned int)(msg[i]);
        }
    }
      
    return result;
}

char * decimal_to_any_base(const uint64_t decimal, const uint8_t base)
{
    // max to base 36
    
    char digits[36] = {
        '0','1','2','3','4','5','6','7',
        '8','9','A','B','C','D','E','F',
        'G','H','I','J','K','L','M','N',
        'O','P','Q','R','S','T','U','V',
        'W','X','Y','Z'};
    
    char * result = (char *)malloc(BUFFER_LENGTH);
    if(NULL == result)
    {
        error("Error", false);
        return NULL;
    }
    
    uint64_t quotient = decimal;
    int remainder;  
    
    int i = 0;
    uint32_t total_len = BUFFER_LENGTH;
    do
    {
        remainder = (int)(quotient % base);
        quotient = quotient / base;      
        
        if(i == (total_len - 1))
        {
            char * new_result = 
                (char *)realloc(result, total_len + BUFFER_LENGTH);
            
            if(NULL == new_result)
            {
                error("Error", false);
                return NULL;
            }
            else
            {
                result = new_result;
            }
        }
        
        result[i++] = digits[remainder];
    }while(quotient > 0);
    
    result[i] = '\0';
    
    /* Reverse string */

    int j;
    for(j = 0; j < i/2; j++)
    {
        // reverse chars of result by swap
        
        result[j] ^= result[i - j - 1];
        result[i - j - 1] ^= result[j];
        result[j] ^= result[i - j - 1];
    }
    
    return result;
}