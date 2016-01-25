#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 300

void error(char *);
char *get_line(void);
char **string_to_arr_of_strings_by_delimiters(char *, char *, size_t *);
void arr_of_strings_sort(char **, size_t, _Bool (*) (char *, char *));
int arr_of_strings_remove_duplicates(char ***, size_t *);
int arr_of_strings_filtered_by_condition(char ***, size_t *, _Bool (*) (char *));
_Bool isPalindrome(char *);
void swap(void *, void *, size_t);
_Bool lexicogr_comparator(char *, char *);

/*
 * Problem 06. Palindromes
 * 
 * Write a program that extracts from a given text all palindromes, e.g. ABBA, 
 * lamal, exe and prints them on the console on a single line, separated by 
 * comma and space. Use spaces, commas, dots, question marks and exclamation 
 * marks as word delimiters. Print only unique palindromes, sorted 
 * lexicographically. String comparison should be case-sensitive as shown in 
 * the example below.
 * 
 * ----------------------------------------------------------------------------
 *                     Input                       |          Output
 * ----------------------------------------------------------------------------
 * Hi,exe? ABBA! Hog fully a string. Bob           | a, ABBA, exe
 * ---------------------------------------------------------------------------- 
 */
int main() 
{
    size_t i;
    char *text;
    size_t count = 0;
    
    printf("Text:");
    if(NULL == (text = get_line()))
    {
        return (EXIT_FAILURE);
    }
    
    char *delimiters = " ,.?!";
    char **arr_of_words = 
        string_to_arr_of_strings_by_delimiters(text, delimiters, &count);
    if(NULL == arr_of_words)
    {
        return (EXIT_FAILURE);
    }
    
    if(0 != arr_of_strings_filtered_by_condition(&arr_of_words, &count, &isPalindrome))
    {
        error("Error when array of strings is filtered by palindromes!");
        return (EXIT_FAILURE);
    }
    
    if(0 != arr_of_strings_remove_duplicates(&arr_of_words, &count))
    {
        error("Error when remove duplicates from array of strings!");
        return (EXIT_FAILURE);
    }
    
    arr_of_strings_sort(arr_of_words, count, &lexicogr_comparator);
    
    printf("\n Output\n");
    for(i = 0; i < count; i++)
    {
        printf("%s", arr_of_words[i]);
        
        if(i < count - 1)
        {
            printf(", ");
        }
    }
    
    for(i = 0; i < count; i++)
    {
        free(arr_of_words[i]);
    }
    
    free(arr_of_words);
    free(text);

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

void arr_of_strings_sort(char **arr, size_t count, 
        _Bool (*comparator) (char *, char *))
{
    size_t i;
    int newN;
    
    do
    {
        newN = 0;
        
        for(i = 1; i < count; i++)
        {
            if(comparator(arr[i - 1], arr[i]))
            {
                swap(&arr[i - 1], &arr[i], sizeof(char *));
                
                newN = i;
            }
        }
        
        count = newN; // best bubble sort optimization
        
    }while(newN != 0);
}

int arr_of_strings_remove_duplicates(char ***arr, size_t *count)
{
    errno = 0;
    char **new_arr = (char **)malloc(*count * sizeof(char *));
    if(errno != 0)
    {
        error("Not enough memory!");
        return (EXIT_FAILURE);
    }
    
    size_t i, j, new_count = 0;
    
    for(i = 0; i < *count; i++)
    {
        if(NULL != (*arr)[i])
        {
            errno = 0;
            new_arr[new_count] = (char *)malloc(strlen((*arr)[i]) + 1);
            if(errno != 0)
            {
                error("Not enough memory!");
                return (EXIT_FAILURE);
            }
            
            strcpy(new_arr[new_count], (*arr)[i]);
            new_count++;
                    
            for(j = i + 1; j < *count; j++)
            {
                if(NULL != (*arr)[j])
                {
                    if(strcmp((*arr)[i], (*arr)[j]) == 0)
                    {
                        free((*arr)[j]);
                        (*arr)[j] = NULL;
                    }
                }
            }
        }
    }
    
    if(new_count > 0)
    {
        errno = 0;
        char ** small_arr = (char **)realloc(new_arr, new_count * sizeof(char *));
        if(errno != 0)
        {
            error("Error when realloc!");
            return (EXIT_FAILURE);
        }
        
        for(i = 0; i < *count; i++)
        {
            if(NULL != (*arr)[i])
            {
                free((*arr)[i]);
            }
        }
        
        free(*arr);
        
        *arr = small_arr;
        *count = new_count;
    }
    
    return 0;
}

int arr_of_strings_filtered_by_condition(char ***arr, size_t *count, 
        _Bool (*condition) (char *))
{
    errno = 0;
    char **new_arr = (char **)malloc(*count * sizeof(char *));
    if(errno != 0)
    {
        error("Not enough memory!");
        return (EXIT_FAILURE);
    }
    
    size_t i, new_count = 0;
    
    for(i = 0; i < *count; i++)
    {
        if(false == condition((*arr)[i]))
        {
            free((*arr)[i]);
            (*arr)[i] = NULL;
            
            continue;
        }
        
        errno = 0;
        new_arr[new_count] = (char *)malloc(strlen((*arr)[i]) + 1);
        if(errno != 0)
        {
            error("Not enough memory!");
            return (EXIT_FAILURE);
        }
        
        strcpy(new_arr[new_count], (*arr)[i]);
        new_count++;
    }
    
    if(new_count > 0)
    {
        errno = 0;
        char ** small_arr = (char **)realloc(new_arr, new_count * sizeof(char *));
        if(errno != 0)
        {
            error("Error when realloc!");
            return (EXIT_FAILURE);
        }
        
        for(i = 0; i < *count; i++)
        {
            if(NULL != (*arr)[i])
            {
                free((*arr)[i]);
            }
        }
        
        free(*arr);
        
        *arr = small_arr;
        *count = new_count;
    }
    
    return 0;
}

_Bool isPalindrome(char *str)
{
    size_t i;
    size_t len = strlen(str);
    
    for(i = 0; i < len/2; i++)
    {
        if(str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    
    return true;
}

void swap(void *ptr1, void *ptr2, size_t size)
{
    void *tmp = malloc(size);
    if(NULL != tmp)
    {
        memcpy(tmp, ptr1, size);
        memcpy(ptr1, ptr2, size);
        memcpy(ptr2, tmp, size);
        
        free(tmp);
    }
}

_Bool lexicogr_comparator(char *s1, char *s2)
{
    size_t len1 = strlen(s1);    
    size_t len2 = strlen(s2);
    
    size_t i = 0;
    size_t len = (len1 < len2) ? len1 : len2;
    
    while(i < len)
    {
        if(tolower(s1[i]) > tolower(s2[i]) 
                || ((tolower(s1[i]) == tolower(s2[i]) && (s1[i] < s2[i]))))
        {
            return true;
        }
        else if(tolower(s1[i]) < tolower(s2[i])
                || ((tolower(s1[i]) == tolower(s2[i]) && (s1[i] > s2[i]))))
        {
            return false;
        }
        
        i++;
    }
    
    if(len1 <= len2)
        return false;
    else
        return true;
}