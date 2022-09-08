#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"
#include "setup.h"
#include "gameloop.h"
#include "terminal.h"
#include "random.h"

int main(int argc, char* argv[])
{
    char** map;
    int nR,nC,pR,pC,i;
    int** Xs;
    if(argc < 5)
    {
        printf("Please run in the format of: './prog <row-size> <col-size> <player-row> <player-col>");
        return 0;
    }
    nR = atoi(argv[1]);
    nC = atoi(argv[2]);
    pR = atoi(argv[3]);
    pC = atoi(argv[4]);
    
    

    Xs = (int**)malloc((nR*nC)*sizeof(int*));
    /*for(i=0;i<(nR*nC);i++)
    {
        Xs[i] = {0,0};
    }

    memset(Xs, 0, (nR*nC) * sizeof(int*));
    Xs = (int**)calloc((nR*nC), sizeof(int*));*/
    for(i=0;i<(nR*nC);i++)
    {
        /*Xs[i] = (int*)calloc(2, sizeof(int));*/
        Xs[i] = (int*)malloc(2*sizeof(int));
        Xs[i][0] = 0;
        Xs[i][1] = 0;

    }
    initRandom();
    
    map = setupMap(map, nR, nC, pR, pC, Xs);
    printMap(map,nR,nC);
    while(1)
    {
        playerInput(&pR,&pC,nR,nC);
        xUpdate(&Xs,nR,nC,pR,pC);
        map = setupMap(map, nR, nC, pR, pC, Xs);
        printMap(map,nR,nC);
    }
    free(map);
    free(Xs);
    return 0;
    
}