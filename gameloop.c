#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "gameloop.h"

void printMap(char** map, int nR, int nC)
{
    int i,j;
    for(i=0;i<nR;i++)
    {
        for(j=0;j<nC;j++)
        {
                printf("%c",map[i][j]);
        }
        printf("\n");
    }
}