#include <stdio.h>
#include <stdlib.h>

/*
 * Problem_05._Longest_Increasing_Sequence
 * 
 * Write a program to find all increasing sequences inside an array of integers. 
 * The numbers should be entered one at a line. On the first input line you will 
 * be given the count of the numbers. Print the sequences in the order of their 
 * appearance in the input array, each at a single line. Separate the sequence 
 * elements by a space. Find also the longest increasing sequence and print it 
 * at the last line. If several sequences have the same longest length, print 
 * the left-most of them.
 */
int main() 
{
    int n;
    
    int startIdxOfLastSeq = 0;
    int lastSeqLength = 0;
    
    int startIdxOfLongestSeq = 0;
    int longestSeqLength = 0;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    int *arr = malloc(n * sizeof(int));
    
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("\n Output\n");
    printf("%d ", arr[0]);
    for(i = 1; i < n; i++)
    {
        if(arr[i] <= arr[i - 1])
        {
            printf("\n");
            lastSeqLength = i - startIdxOfLastSeq;
            
            if(lastSeqLength > longestSeqLength)
            {
                startIdxOfLongestSeq = startIdxOfLastSeq;
                longestSeqLength = lastSeqLength;
            }
            
            startIdxOfLastSeq = i;
        }
        
        printf("%d ", arr[i]);
    }
    
    lastSeqLength = i - startIdxOfLastSeq;
    if(lastSeqLength > longestSeqLength)
    {
        startIdxOfLongestSeq = startIdxOfLastSeq;
        longestSeqLength = lastSeqLength;
    }
    
    printf("\nLongest: ");
    for(i = startIdxOfLongestSeq; i < (startIdxOfLongestSeq + longestSeqLength); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return (EXIT_SUCCESS);
}

