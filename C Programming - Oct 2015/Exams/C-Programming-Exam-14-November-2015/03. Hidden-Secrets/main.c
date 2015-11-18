#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64

/*
 * 
 */
int main(int argc, char** argv) 
{
    if(argc < 2)
    {
        printf("Usage: [<src-file-1> <src-file-2> ...]\n");
        return -1;
    }
    
    char * extension = strrchr(argv[1], '.');
    int ext_len = strlen(extension);
    
    char dest_file_path[strlen("merged") + ext_len + 1];
    
    strcpy(dest_file_path, "merged");
    strcat(dest_file_path, extension);
    
    FILE * dest_file = fopen(dest_file_path, "wb");
    if(NULL == dest_file)
    {        
        printf("%s: No such file or directory\n", dest_file_path);
        return -1;
    }
    
    int num_of_src_files = argc - 1;
    
    size_t read_bytes;
    size_t write_bytes;
    size_t hs;
    char buffer[BUFFER_SIZE];
    
    size_t i;
    for(i = 1; i <= num_of_src_files; i++)
    {
        FILE * src_file = fopen(argv[i], "rb");
        if(NULL == src_file)
        {
            fclose(dest_file);
            
            printf("%s: No such file or directory\n", argv[i]);
            return -1;
        }
        
        do
        {
            if((read_bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0)
            {
                hs = read_bytes - 4;
                
                if(buffer[hs] == 0x33 
                        && buffer[hs + 1] == 0x34 
                        && buffer[hs + 2] == 0x35 
                        && buffer[hs + 3] == 0x36)
                {
                    /* Apple */
                    
                    write_bytes = fwrite(buffer, 1, read_bytes - 4, dest_file);
                }
                else if(buffer[hs] == 0x21 
                        && buffer[hs + 1] == 0x22 
                        && buffer[hs + 2] == 0x23 
                        && buffer[hs + 3] == 0x24)
                {
                    /* Leaf */                  
                    
                    write_bytes = fwrite(buffer, 1, (read_bytes - 4) / 2, dest_file);                
                }
                else if(buffer[hs] == 0x2B 
                        && buffer[hs + 1] == 0x2C 
                        && buffer[hs + 2] == 0x2D 
                        && buffer[hs + 3] == 0x2E)
                {
                    /* Cross */
                    
                    // skip writing
                }
            }
        }while(read_bytes > 0);  
        
        /* Free allocated resources */
        
        if(src_file)
            fclose(src_file);
    }

    /* Print output */
    
    printf("Eureka!\n");

    /* Free allocated resources */
    
    if(dest_file)
        fclose(dest_file);
    
    return (EXIT_SUCCESS);

}

