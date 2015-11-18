#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define BUFFER_LENGTH 200

struct PlayerPosition {
    int prev_row;
    int prev_col;
    int row;
    int col;
};

ssize_t get_line(char **, size_t *, FILE *);
void print_game_over(struct PlayerPosition *);
int get_bit_from_any_number(const size_t, const void * const, const uint32_t, 
        const _Bool, const _Bool);
int write_bit_to_any_number(const size_t, const void * const, const uint32_t, 
        const uint8_t, const _Bool, const _Bool);

int main(int argc, char** argv) 
{
    int n;
    scanf("%2d", &n);
    
    int c;
    // flush stdin
    while ((c = getchar()) != '\n' && c != EOF);
    
    uint32_t numbers[n];
    
    size_t i;
    for(i = 0; i < n; i++)
    {
        scanf("%u", &numbers[i]);
        
        // flush stdin
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    char * command = NULL;
    size_t command_buf_size = 0;
    ssize_t command_len;
    
    struct PlayerPosition player;
    
    player.row = 0;
    player.col = 0;
    
    while(-1 != (command_len = get_line(&command, &command_buf_size, stdin)))
    {
        if(strcmp(command, "end") == 0)
            break;
        
        player.prev_row = player.row;
        player.prev_col = player.col;
        
        if(strcmp(command, "left") == 0)
        {
            player.col = (player.col + 1) % 32;
        }
        else if(strcmp(command, "right") == 0)
        {
            if(player.col == 0)
                player.col = 31;
            else
                player.col -= 1;
        }
        else if(strcmp(command, "up") == 0)
        {
            if(player.row == 0)
                player.row = n - 1;
            else
                player.row -= 1;
        }
        else if(strcmp(command, "down") == 0)
        {
            player.row = (player.row + 1) % n;
        }
        
        int bit = get_bit_from_any_number(sizeof(uint32_t), 
                &(numbers[player.row]), player.col, true, true);
        
        if(bit == 1)
        {
            print_game_over(&player);
            break;
        }
        else
        {
            write_bit_to_any_number(sizeof(uint32_t), &(numbers[player.prev_row]), 
                    player.prev_col, 0, true, true);
                    
            write_bit_to_any_number(sizeof(uint32_t), &(numbers[player.row]), 
                    player.col, 1, true, true);
        }
    }    
    
    /* Print output */
    
    for(i = 0; i < n; i++)
    {
        printf("%u\n", numbers[i]);
    }
    
    /* Free allocated resources */
    
    if(command)
        free(command);

    return (EXIT_SUCCESS);
}

void print_game_over(struct PlayerPosition * player)
{
    printf("GAME OVER. Stepped a mine at %d %d\n", player->row, player->col);
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
            //error("Error when malloc() in get_line() function.", false);
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
                
                //error("Error when realloc in get_line() function.", false);
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