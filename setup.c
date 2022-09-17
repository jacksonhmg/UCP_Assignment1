#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"
#include "setup.h"
#include "gameloop.h"
#include "checkers.h"


void setupMap(char***map, int nR, int nC, int pR, int pC, int gR, int gC) /*initialise first iteration of map*/
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
                (*map)[i][j] =  ' '; /*create empty space look*/
            }
        }
    }

    (*map)[gR][gC] = 'G';
    (*map)[pR][pC] = 'P';
}


int setupGame(int argc, char* argv[]) 
{ /*used for initialising command line input, organising map setup, initialising game loop, everything set up wise*/
    char** map;
    
    int nR,nC,pR,pC,gR,gC,check;

    check = inputCheck(&nR,&nC,&pR,&pC,&gR,&gC,argc,argv);
    if(!check)
    {
        return 0; /*exit program before continuing*/
    }

    setupMap(&map,nR,nC,pR,pC,gR,gC);

    printMap(map,nR,nC);
    
    gameloop(map, nR, nC, pR, pC, gR, gC);
    return 0;
}