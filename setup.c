#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"
#include "setup.h"

/*void initGame(char** map, int pmapSize[], char* argv[], int argc)
{
    
}*/

char** setupMap(char**map, int nR, int nC, int pR, int pC)
{
    int i,j;
    system("clear");
    map = (char**)malloc(nR*sizeof(char*));
    for(i=0;i<nR;i++)
    {
        map[i] = (char*)malloc(nC * sizeof(char));
    }
    for(i=0;i<nR;i++)
    {
        map[i][nC-1] = 'X';
    }
    for(i=0;i<nR;i++)
    {
        map[i][0] = 'X';
    }
    for(i=0;i<nC;i++)
    {
        map[0][i] = 'X';
    }
    for(i=0;i<nC;i++)
    {
        map[nR-1][i] = 'X';
    }
    
    for(i=0;i<nR;i++)
    {
        for(j=0;j<nC;j++)
        {
            if(map[i][j] == 0)
            {
                map[i][j] =  ' ';
            }
        }
    }

    map[pR][pC] = 'P';
    return map;
}