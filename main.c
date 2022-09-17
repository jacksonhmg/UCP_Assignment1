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

    check = inputCheck(&nR,&nC,&pR,&pC,&gR,&gC,argc,argv);
    if(!check)
    {
        return 0;
    }

    setupMap2(&map,nR,nC,pR,pC,gR,gC);

    initRandom();

    printMap(map,nR,nC);
    while(!winCond(pR,pC,gR,gC) && !loseCond(pR,pC,gR,gC,nR,nC,map))
    {
        optionsPrint();
        map[pR][pC] = ' ';
        valid = playerInput(&pR,&pC,nR,nC,map);
        map[pR][pC] = 'P';
        if(valid)
        {
            xUpdate(map, nR, nC);
        }
        printMap(map,nR,nC);
    }
    if(winCond(pR,pC,gR,gC))
    {
        printf("You Win!\n");
        printf("Congratulations!\n");
    }
    
    for(i = 0; i < nR; i++)
    {
        free(map[i]);
    }
    free(map);
    
    return 0;
}