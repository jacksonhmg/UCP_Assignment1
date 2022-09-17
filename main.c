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
    
    int nR,nC,pR,pC,gR,gC,i,valid,check;
    int** Xs;
    
    
    check = inputCheck(&nR,&nC,&pR,&pC,&gR,&gC,argc,argv);
    if(!check)
    {
        return 0;
    }

    setupMap2(&map,nR,nC,pR,pC,gR,gC);

    /*map = (char**)calloc(nR,sizeof(char*));
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
        optionsPrint();
        valid = playerInput(&pR,&pC,nR,nC,Xs);
        if(valid)
        {
            xUpdate(Xs,nR,nC,pR,pC, gR, gC);
        }
        map = setupMap(map, nR, nC, pR, pC, Xs, gR, gC);
        printMap(map,nR,nC);
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
    free(Xs);*/
    return 0;
    
}