#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"
#include "setup.h"
#include "gameloop.h"


char** setupMap(char**map, int nR, int nC, int pR, int pC, int** Xs, int gR, int gC)
{
    int i,j;
    system("clear");
    map = (char**)calloc(nR,sizeof(char*));
    for(i=0;i<nR;i++)
    {
        map[i] = (char*)calloc(nC, sizeof(char));
    }
    for(i=0;i<nR;i++)
    {
        map[i][nC-1] = '*';
    }
    for(i=0;i<nR;i++)
    {
        map[i][0] = '*';
    }
    for(i=0;i<nC;i++)
    {
        map[0][i] = '*';
    }
    for(i=0;i<nC;i++)
    {
        map[nR-1][i] = '*';
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

    map[gR][gC] = 'G';
    map[pR][pC] = 'P';

    for(i=0;i<(nR*nC);i++)
    {
        if((Xs[i][0] != 0) && (Xs[i][1] != 0))
        {
            map[Xs[i][0]][Xs[i][1]] = 'X';
        }
    }
    
    return map;
}

void setupMap2(char***map, int nR, int nC, int pR, int pC, int gR, int gC)
{
    int i,j;
    system("clear");
    *map = (char**)calloc(nR,sizeof(char*));
    for(i=0;i<nR;i++)
    {
        (*map)[i] = (char*)calloc(nC, sizeof(char));
    }
    for(i=0;i<nR;i++)
    {
        (*map)[i][nC-1] = '*';
    }
    for(i=0;i<nR;i++)
    {
        (*map)[i][0] = '*';
    }
    for(i=0;i<nC;i++)
    {
        (*map)[0][i] = '*';
    }
    for(i=0;i<nC;i++)
    {
        (*map)[nR-1][i] = '*';
    }
    
    for(i=0;i<nR;i++)
    {
        for(j=0;j<nC;j++)
        {
            if((*map)[i][j] == 0)
            {
                (*map)[i][j] =  ' ';
            }
        }
    }

    (*map)[gR][gC] = 'G';
    (*map)[pR][pC] = 'P';
}


