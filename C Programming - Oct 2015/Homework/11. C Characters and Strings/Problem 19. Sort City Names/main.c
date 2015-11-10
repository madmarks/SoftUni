#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
void arr_of_strings_sort_by_modified_bubble_sort(char **, size_t, int (*) (const char *, const char *));
void arr_of_strings_sort_by_insertion_sort(char **, size_t, int (*) (const char *, const char *));
void arr_of_strings_sort_by_selection_sort(char **, size_t, int (*) (const char *, const char *));
void swap(void *, void *, size_t);

/*
 * Problem 19. * Sort City Names
 * 
 * You are given a list of cities. You have to process them and sort them in 
 * ascending order. On the first input line, you are given the count of the 
 * cities. Use an algorithm other than bubble sort.
 * 
 * ----------------------------------------------------------------------------
 *                   Input                   |            Output
 * ----------------------------------------------------------------------------
 * 4                                         | Aitos
 * Sofia                                     | Burgas
 * Burgas                                    | Pleven
 * Aitos                                     | Sofia
 * Pleven                                    |
 * ----------------------------------------------------------------------------
 * 2                                         | Pamporovo
 * Svoge                                     | Svoge
 * Pamporovo                                 |
 * ----------------------------------------------------------------------------
 * 1                                         | New york
 * New york                                  |
 * ----------------------------------------------------------------------------
 */
int main() 
{
    size_t num_cities;
    char * line = NULL;
    size_t line_buf_size = 0;
    
    printf("Number of cities:");
    scanf("%lu", &num_cities);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    char **input = (char **)malloc(num_cities * sizeof(char *));
    if(NULL == input)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    size_t i;
    ssize_t len;
    for(i = 0; i < num_cities; i++)
    {
        if(-1 == (len = get_line(&line, &line_buf_size, stdin)))
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }
        
        input[i] = (char *)malloc(len + 1);
        if(NULL == input[i])
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }            

        strcpy(input[i], line);
    }
    
    //arr_of_strings_sort_by_modified_bubble_sort(input, num_cities, &strcmp);
    arr_of_strings_sort_by_insertion_sort(input, num_cities, &strcmp);
    //arr_of_strings_sort_by_selection_sort(input, num_cities, &strcmp);
    
    /* Print result */
    
    printf("\n Output\n");
    for(i = 0; i < num_cities; i++)
    {
        printf("%s\n", input[i]);
    }
    
    /* Free allocated memory */
    
    for(i = 0; i < num_cities; i++)
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

void arr_of_strings_sort_by_modified_bubble_sort(char **arr, size_t n, 
        int (*comparator) (const char *, const char *))
{
    size_t i;
    int newN;
    
    do
    {
        newN = 0;
        
        for(i = 1; i < n; i++)
        {
            if(0 <= comparator(arr[i - 1], arr[i]))
            {
                swap(&arr[i - 1], &arr[i], sizeof(char *));
                
                newN = i;
            }
        }
        
        n = newN; // best bubble sort optimization
        
    }while(newN != 0);
}

void arr_of_strings_sort_by_insertion_sort(char **arr, size_t n, 
        int (*comparator) (const char *, const char *))
{
    /* 
     * Usually, insertion sort will perform less comparisons than selection 
     * sort, depending on the degree of "sortedness" of the array. While 
     * selection sort must scan the remaining parts of the array when placing 
     * an element, insertion sort only scans as many elements as necessary. 
     * That means that when the array is already sorted or almost sorted, 
     * insertion sort performs in O(n) time. 
     */
    
    size_t i, j;
    
    for (i = 1 ; i < n; i++) 
    {
        j = i;

        while ( j > 0 && comparator(arr[j], arr[j-1]) < 0) 
        {
            swap(&arr[j], &arr[j - 1], sizeof(char *));

            j--;
        }
    }
}

void arr_of_strings_sort_by_selection_sort(char **arr, size_t n, 
        int (*comparator) (const char *, const char *))
{
    /* 
     * One advantage of selection sort against insertion sort, is that the 
     * number of writes (swaps) is in O(n), while in insertion sort it is 
     * in O(n^2). This may be important if you are sorting on Flash memory, 
     * for example, because writes reduce the lifespan of Flash memory. 
     */
    
    /* arr[0] to arr[n-1] is the array to sort */
    size_t i,j;
    size_t iMin;

    /* advance the position through the entire array */
    /*   (could do j < n-1 because single element is also min element) */
    for (j = 0; j < n - 1; j++) 
    {
        /* find the min element in the unsorted arr[j ... n-1] */

        /* assume the min is the first element */
        iMin = j;
        
        /* test against elements after j to find the smallest */
        for ( i = j + 1; i < n; i++) 
        {
            /* if this element is less, then it is the new minimum */
            if (comparator(arr[i], arr[iMin]) < 0) 
            {
                /* found new minimum; remember its index */
                iMin = i;
            }
        }

        if(iMin != j) 
        {
            swap(&arr[j], &arr[iMin], sizeof(char *));
        }
    }
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