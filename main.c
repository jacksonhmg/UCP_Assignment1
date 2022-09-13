#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"
#include "setup.h"
#include "gameloop.h"
#include "terminal.h"
#include "random.h"
#include "checkers.h"

int main(int argc, char* argv[])
{
    char** map;
    int nR,nC,pR,pC,gR,gC,i;
    int** Xs;
    if(argc < 7)
    {
        printf("Please run in the format of: './prog <row-size> <col-size> <player-row> <player-col> <goal-row> <goal-col>");
        return 0;
    }
    nR = atoi(argv[1]);
    nC = atoi(argv[2]);
    pR = atoi(argv[3]);
    pC = atoi(argv[4]);
    gR = atoi(argv[5]);
    gC = atoi(argv[6]);
    
    Xs = (int**)malloc((nR*nC)*sizeof(int*));
    for(i=0;i<(nR*nC);i++)
    {
        Xs[i] = (int*)malloc(2*sizeof(int));
        Xs[i][0] = 0;
        Xs[i][1] = 0;
    }

    initRandom();
    
    map = setupMap(map, nR, nC, pR, pC, Xs, gR, gC);
    printMap(map,nR,nC);
    while(!winCond(pR,pC,gR,gC) && !loseCond(pR,pC,gR,gC,Xs,nR,nC))
    {
        for(i = 0; i < nR; i++)
        {
            free(map[i]);
        }
        free(map);
        playerInput(&pR,&pC,nR,nC,Xs);
        xUpdate(Xs,nR,nC,pR,pC, gR, gC);
        map = setupMap(map, nR, nC, pR, pC, Xs, gR, gC);
        printMap(map,nR,nC);
    }
    if(winCond(pR,pC,gR,gC))
    {
        printf("You Win!\n");
        printf("Congratulations!\n");
    }
    if(loseCond(pR,pC,gR,gC,Xs,nR,nC))
    {
        printf("You Lose!\n");
        printf("Unlucky!\n");
    }
    for(i = 0; i < nR; i++)
    {
        free(map[i]);
    }
    free(map);
    for(i = 0; i < (nR*nC); i++)
    {
        free(Xs[i]);
    }
    free(Xs);
    return 0;
    
}