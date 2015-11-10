#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define BUFFER_LENGTH 100

void error(char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
char **string_to_arr_of_strings_by_delimiters(char *, char *, size_t *);
int get_data(char *, char *, int *, char *);
double get_calculated_number(char, int, char);
double my_round(double, unsigned int);

/*
 * Problem 22. * Letters Change Numbers
 * 
 * This problem is from the Java Basics exam (8 February 2015). You may check 
 * your solution here.
 * 
 * Nakov likes Math. But he also likes the English alphabet a lot. He invented a 
 * game with numbers and letters from the English alphabet. The game was simple. 
 * You get a string consisting of a number between two letters. Depending on 
 * whether the letter was in front of the number or after it you would perform 
 * different mathematical operations on the number to achieve the result. 
 * 
 * First you start with the letter before the number. If it's Upper case you 
 * divide the number by the letter's position in the alphabet. If it's lowercase
 * you multiply the number with the letter's position. Then you move to the 
 * letter after the number. If it's Uppercase you subtract its position from the 
 * resulted number. If it's lowercase you add its position to the resulted 
 * number. But the game became too easy for Nakov really quick. He decided to 
 * complicate it a bit by doing the same but with multiple strings keeping track 
 * of only the total sum of all results. Once he started to solve this with more 
 * strings and bigger numbers it became quite hard to do it only in his mind. 
 * So he kindly asks you to write a program that calculates the sum of all 
 * numbers after the operations on each number have been done.
 * 
 * For example, you are given the sequence "A12b s17G". We have two strings - 
 * "A12b"and "s17G". We do the operations on each and sum them. We start with 
 * the letter before the number on the first string. A is Uppercase and its 
 * position in the alphabet is 1. So we divide the number 12 with the position 1 
 * (12 / 1 = 12). Then we move to the letter after the number. b is lowercase and 
 * its position is 2. So we add 2 to the resulted number (12 + 2 = 14). 
 * Similarly for the second string s is lowercase and its position is 19 so we 
 * multiply it with the number (17 * 19 = 323). Then we have Uppercase G with 
 * position 7, so we subtract it from the resulted number (323 - 7 = 316). 
 * Finally we sum the 2 results and we get 14 + 316 = 330;
 * 
 * 
 * Input
 * 
 * The input comes from the console as a single line, holding the sequence of 
 * strings. Strings are separated by one or more white spaces.
 * 
 * The input data will always be valid and in the format described. There is no 
 * need to check it explicitly.
 * 
 * 
 * Output
 * 
 * Print at the console a single number: the total sum of all processed numbers 
 * rounded up to two digits after the decimal separator.
 * 
 * 
 * Constraints
 * 
 *   * The count of the strings will be in the range [1 ... 10].
 *   * The numbers between the letters will be 
 *     integers in range [1 ... 2 147 483 647].
 *   * Time limit: 0.3 sec. Memory limit: 16MB.
 * 
 * ----------------------------------------------------------------------------
 *         Input        |  Output  | 
 * ----------------------------------------------------------------------------
 * A12b s17G            | 330.00   | 12 / 1 = 12, 12 + 2 = 14,  
 *                      |          | 17 * 19 = 323, 323 - 7 = 316, 
 *                      |          | 14 + 316 = 330
 * ----------------------------------------------------------------------------
 * P34562Z q2576f H456z | 46015.13 |
 * ----------------------------------------------------------------------------
 * a1A                  | 0.00     |
 * ----------------------------------------------------------------------------
 */
int main() 
{
    char * line = NULL;
    size_t line_buf_size = 0;
    
    ssize_t len;
    size_t num_strings;
    
    printf("Input:");
    if(-1 == (len = get_line(&line, &line_buf_size, stdin)))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }

    char * delimiters = " \t";       

    char ** input = string_to_arr_of_strings_by_delimiters(line, delimiters, 
            &num_strings);

    if(NULL == input)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    double sum = 0.0;
    
    char first_ch;
    int number;
    char last_ch;
    
    size_t i;
    for(i = 0; i < num_strings; i++)
    {
        if(-1 == get_data(input[i], &first_ch, &number, &last_ch))
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }
        
        sum += get_calculated_number(first_ch, number, last_ch);
    }
    
    printf("\n Output\n");
    //printf("%.2lf\n", round(sum * 100.0)/100.0);
    printf("%.2lf\n", my_round(sum, 2));
    
    /* Free allocated memory */
    
    for(i = 0; i < num_strings; i++)
    {
        if(input[i])
            free(input[i]);
    }
    
    if(input)
        free(input);
    
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
    char **arr = (char **)malloc((*count) * sizeof(char *));
    if(NULL == arr)
    {
        error("Not enough memory!", false);
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
        if(NULL == arr[i])
        {
            error("Not enough memory!", false);
            return NULL;
        }
        
        strncpy(arr[i], ptr, len);
               
        ptr += len;
    }
    
    return arr; // must free it in the calling function
}

int get_data(char * src, char * first_ch, int * number, char * last_ch)
{
    size_t src_len = strlen(src);
    size_t buf_len = src_len - 2;
    
    char buffer[buf_len + 1];
    buffer[buf_len] = '\0';
    
    *first_ch = src[0];
    
    strncpy(buffer, src + 1, buf_len);
    *number = atoi(buffer);
    
    *last_ch = src[src_len - 1];
    
    return 0;
}

double get_calculated_number(char first_ch, int number, char last_ch)
{
    double result;
    
    int first_ch_number = tolower(first_ch) - 96;
    int last_ch_number = tolower(last_ch) - 96;
    
    if(isupper(first_ch))
    {
        result = (double)number / (double)first_ch_number;
    }
    else
    {
        result = (double)number * (double)first_ch_number;
    }
    
    if(isupper(last_ch))
    {
        result -= (double)last_ch_number;
    }
    else
    {
        result += (double)last_ch_number;
    }
      
    return result;
}

double my_round(double x, unsigned int digits) 
{
    if (digits > 0) 
    {
        return my_round(x * 10.0, digits - 1) / 10.0;
    }
    else 
    {
        return round(x);
    }
}