#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>


struct DartsBoard {
    float x;
    float y;
    float r;
};

struct BayMilesHead {
    float x;
    float y;
    float r;
};

struct BayMilesArm {
    float topLeftX;
    float topLeftY;
    float bottomRightX;
    float bottomRightY;
};

struct Shot {
    float x;
    float y;
};
int main(int argc, char** argv) 
{
    size_t i;
    
    struct DartsBoard board;
    struct BayMilesHead head;
    struct BayMilesArm arm;
    int number_of_shots;
    struct Shot shot;
    
    scanf("%f%f%f", &(board.x), &(board.y), &(board.r));    
    scanf("%f%f%f", &(head.x), &(head.y), &(head.r));   
    scanf("%f%f%f%f", &(arm.topLeftX), &(arm.topLeftY), 
        &(arm.bottomRightX), &(arm.bottomRightY));   
    scanf("%d", &number_of_shots);
    
    int points = 0;
    int health = 100;
    int shots = 0;
    int hits = 0;
    
    _Bool isInsideArm;
    
    for(i = 0; i < number_of_shots; i++)
    {
        scanf("%f%f", &(shot.x), &(shot.y));
        
        double xyDistanceFromBoardCenter = 
            (shot.x - board.x)*(shot.x - board.x) + 
            (shot.y - board.y)*(shot.y - board.y);
        
        _Bool isInsideBoard = (board.r * board.r) >= xyDistanceFromBoardCenter;
        
        double xyDistanceFromHeadCenter = 
            (shot.x - head.x)*(shot.x - head.x) + 
            (shot.y - head.y)*(shot.y - head.y);
        
        _Bool isInsideHead = (head.r * head.r) >= xyDistanceFromHeadCenter;
        
        _Bool isInsideArm = 
                arm.topLeftX <= shot.x && shot.x <= arm.bottomRightX
                    && arm.bottomRightY <= shot.y && shot.y <= arm.topLeftY;
        
        shots++;
        
        if(isInsideBoard)
        {
            hits++;
            
            if(isInsideHead || isInsideArm)
            {
                points += 25;
            }
            else
            {
                points += 50;
            }
        }
        
        if(isInsideHead)
        {
            health -= 25;
        }
        else if(isInsideArm)
        {
            health -= 30;
        }
        
        if(health <= 0)
        {
            health = 0;
            break;
            //return (EXIT_FAILURE);
        }
    }
    
    //int hit_ratio = (int)(100 *(double)hits / (double)number_of_shots);
    int hit_ratio = (int)(100 *(double)hits / (double)shots);
    
    printf("Points: %d\n", points);
    printf("Hit ratio: %d%c\n", hit_ratio, '%');
    printf("Bay Mile: %d\n", health);

    return (EXIT_SUCCESS);
}