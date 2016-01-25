#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

int clear_file(const char *);

/*
 * 
 */
int main(int argc, char** argv) 
{
    if(argc < 3)
    {
        printf("Usage: <src-file> <dest-file>\n");
        return -1;
    }
    
    FILE * src_file = fopen(argv[1], "rb");
    if(NULL == src_file)
    {
        printf("%s: No such file or directory\n", argv[1]);
        return -1;
    }
    
    /* Check for destination file */
    FILE * dst_file = fopen(argv[2], "rb");
    if(NULL == dst_file)
    {
        printf("%s: No such file or directory\n", argv[2]);
        return -1;
    }
    else
    {
        if(0 != fclose(dst_file))
            return -1;
    }
    
    /* Clear destination file */
    if(-1 == clear_file(argv[2]))
    {
        printf("%s: No such file or directory\n", argv[2]);
        return -1;
    }
    
    FILE * dest_file = fopen(argv[2], "rb+");
    if(NULL == dest_file)
    {
        free(src_file);
        
        printf("%s: No such file or directory\n", argv[2]);
        return -1;
    }
    
    size_t read_bytes;
    size_t write_bytes;
    size_t idx_of_second_half;
    char buffer[BUFFER_SIZE];
    
    do
    {
        if((read_bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0)
        {
            idx_of_second_half = read_bytes / 2;
            
            if(idx_of_second_half > 0)
            {
                void *tmp = malloc(idx_of_second_half);
                if(NULL != tmp)
                {
                    memcpy(tmp, buffer, idx_of_second_half);
                    memmove(buffer, &buffer[idx_of_second_half], 
                            read_bytes - idx_of_second_half);
                    memcpy(&buffer[read_bytes - idx_of_second_half], tmp, 
                            idx_of_second_half);

                    free(tmp);
                }
            }
            
            write_bytes = fwrite(buffer, 1, read_bytes, dest_file);
        }
        else
            write_bytes = 0;
        
    }while(read_bytes > 0 && (read_bytes == write_bytes));

    /* Print output */
    
    printf("Success!\n");

    /* Free allocated resources */
    
    if(dest_file)
        fclose(dest_file);
    
    if(src_file)
        fclose(src_file);
    
    return (EXIT_SUCCESS);
}

int clear_file(const char *filename)
{ 
    FILE *output = fopen(filename, "wb");
    
    if(output && (0 == fclose(output)))
        return 0;
    else
        return -1;
}