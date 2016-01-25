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
char **string_to_arr_of_strings_by_delimiters(char *, const char *, size_t *);
int get_bit_from_any_number(const size_t, const void * const, const uint32_t, 
        const _Bool, const _Bool);
int get_count_of_one_bits_of_any_number(const size_t, const void * const, 
        const uint32_t, const uint32_t, const _Bool, const _Bool);
int write_bit_to_any_number(const size_t, const void * const, const uint32_t, 
        const uint8_t, const _Bool, const _Bool);

/*
 * 
 */
int main(int argc, char** argv) 
{
    int n;
    scanf("%2d", &n);
    
    int c;
    // flush stdin
    while ((c = getchar()) != '\n' && c != EOF);
    
    unsigned long long numbers[n];
    
    size_t i;
    for(i = 0; i < n; i++)
    {
        scanf("%llu", &numbers[i]);
        
        // flush stdin
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    char * command = NULL;
    size_t command_buf_size = 0;
    ssize_t command_len;
    
    char ** command_parameters = NULL;
    size_t num_of_command_parameters = 0;
    
    while(-1 != (command_len = get_line(&command, &command_buf_size, stdin)) 
            && strcmp(command, "end") != 0)
    {
        command_parameters = 
            string_to_arr_of_strings_by_delimiters(command, " ", 
                &num_of_command_parameters);

        if(NULL == command_parameters)
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }
        
        int position = atoi(command_parameters[1]);
        
        if(strcmp(command_parameters[0], "left") == 0)
        {
            for(i = 0; i < n; i++)
            {
                int ones = get_count_of_one_bits_of_any_number(8, &numbers[i], 
                        position, 63, true, true);
                
                unsigned long long mask;
                
                if(ones == 64)
                    mask = 0xFFFFFFFFFFFFFFFFULL;                    
                else
                    mask = ((1ULL << ones) - 1ULL) << (64 - ones);
             
                if(position == 0)
                    numbers[i] = 0ULL;
                else
                    numbers[i] = (numbers[i] << (64 - position)) >> (64 - position);
                
                numbers[i] ^= mask;
            }            
        }
        else if(strcmp(command_parameters[0], "right") == 0)
        {
            for(i = 0; i < n; i++)
            {
                int ones = get_count_of_one_bits_of_any_number(8, &numbers[i], 
                        0, position, true, true);
                
                unsigned long long mask;
                
                if(ones == 64)
                    mask = 0xFFFFFFFFFFFFFFFFULL;                    
                else
                    mask = (1ULL << ones) - 1ULL;
                
                if(position == 63)
                    numbers[i] = 0ULL;
                else
                    numbers[i] = (numbers[i] >> (position + 1)) << (position + 1);
                
                numbers[i] ^= mask;
            }
        }

        for(i = 0; i < num_of_command_parameters; i++)
        {
            if(command_parameters[i])
                free(command_parameters[i]);
        }

        if(command_parameters)
            free(command_parameters);        
    }
    
    /* Print output */
    
    for(i = 0; i < n; i++)
    {
        printf("%llu\n", numbers[i]);
    }
    
    /* Free allocated resources */
    
    if(command)
        free(command);

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

char **string_to_arr_of_strings_by_delimiters(char *buffer, 
        const char *delimiters, size_t *count)
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

int get_bit_from_any_number(const size_t size_of_type, const void * const ptrNum, 
        const uint32_t pos, const _Bool littleEndian, 
        const _Bool bits_counted_from_the_rightmost)
{
    if((8 * size_of_type) <= pos)
        return -1;
    
    unsigned char *pByte = (unsigned char *)ptrNum;
    int index;
    int shift_count;
    
    if(littleEndian)
        index = pos / 8;
    else
        index = size_of_type - (pos / 8) - 1;
    
    if(bits_counted_from_the_rightmost)
        shift_count = pos % 8;
    else
        shift_count = 7 - (pos % 8);
    
    if((pByte[index] >> shift_count) & 1)
        return 1;
    else
        return 0;
}

int get_count_of_one_bits_of_any_number(const size_t size_of_type, 
        const void * const ptrNum, const uint32_t start_pos,
        const uint32_t end_pos, const _Bool littleEndian, 
        const _Bool bits_counted_from_the_rightmost)
{
    if((8 * size_of_type) <= start_pos || (8 * size_of_type) <= end_pos)
        return -1;
    
    if(start_pos > end_pos)
        return -1;
    
    size_t i;
    int bit;
    int count = 0;
    for(i = start_pos; i <= end_pos; i++)
    {
        if(-1 != (bit = get_bit_from_any_number(size_of_type, ptrNum, i, littleEndian, 
                bits_counted_from_the_rightmost)))
        {
            count += bit;
        }
        else
        {
            error("Error", false);
            return -1;
        }
    }
    
    return count;
}

int write_bit_to_any_number(const size_t size_of_type, const void * const ptrNum, 
        const uint32_t pos, const uint8_t bit, const _Bool littleEndian, 
        const _Bool bits_counted_from_the_rightmost)
{
    if((8 * size_of_type) <= pos)
        return -1;
    
    if(bit != 0 && bit != 1)
        return -1;
    
    unsigned char *pByte = (unsigned char *)ptrNum;
    int index;
    int shift_count;
    
    if(littleEndian)
        index = pos / 8;
    else
        index = size_of_type - (pos / 8) - 1; 
    
    if(bits_counted_from_the_rightmost)
        shift_count = pos % 8;
    else
        shift_count = 7 - (pos % 8);
    
    uint8_t clearing_bit_mask = ~((uint8_t)1 << shift_count);
    
    pByte[index] = (pByte[index] & clearing_bit_mask) | (bit << shift_count);
    
    return 0;
}