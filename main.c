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
    nR = atoi(argv[1]) +2;
    nC = atoi(argv[2]) +2;
    pR = atoi(argv[3]) +1;
    pC = atoi(argv[4]) +1;
    gR = atoi(argv[5]) +1;
    gC = atoi(argv[6]) +1;

    if(pR <= 0 || pR > nR - 2 || pC <= 0 || pC > nC - 2)
    {
        printf("Player position placed outside of map area!\n");
        return 0;
    }
    if(gR <= 0 || gR > nR - 2 || gC <= 0 || gC > nC - 2)
    {
        printf("Goal position placed outside of map area!\n");
        return 0;
    }
    

    map = (char**)calloc(nR,sizeof(char*));
    for(i=0;i<nR;i++)
    {
        map[i] = (char*)calloc(nC, sizeof(char));
    }

    Xs = (int**)malloc((nR*nC)*sizeof(int*));
    for(i=0;i<(nR*nC);i++)
    {
        Xs[i] = (int*)malloc(2*sizeof(int));
        Xs[i][0] = 0;
        Xs[i][1] = 0;
    }

    initRandom();
    for(i = 0; i < nR; i++)
    {
        free(map[i]);
    }
    free(map);
    map = setupMap(map, nR, nC, pR, pC, Xs, gR, gC);
    printMap(map,nR,nC);
    while(!winCond(pR,pC,gR,gC) && !loseCond(pR,pC,gR,gC,nR,nC,map,Xs))
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
        #ifdef DEBUG
        printf("YOOOOO\n");
        #endif
    }
    if(winCond(pR,pC,gR,gC))
    {
        printf("You Win!\n");
        printf("Congratulations!\n");
    }
    if(loseCond(pR,pC,gR,gC,nR,nC,map,Xs))
    {
        printf("\n");
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