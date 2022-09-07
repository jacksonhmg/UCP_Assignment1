#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"
#include "setup.h"
#include "gameloop.h"
#include "terminal.h"

int main(int argc, char* argv[])
{
    char **map;
    int nR,nC,pR,pC;
    char input;
    
    
    if(argc < 5)
    {
        printf("Please run in the format of: './prog <row-size> <col-size> <player-row> <player-col>");
        return 0;
    }
    nR = atoi(argv[1]);
    nC = atoi(argv[2]);
    pR = atoi(argv[3]);
    pC = atoi(argv[4]);
    map = setupMap(map, nR, nC, pR, pC);
    printMap(map,nR,nC);
    while(1)
    {
        disableBuffer();
        scanf(" %c",&input);
        enableBuffer();
        if(input == 'a')
        {
            pC--;
        }
        if(input == 'd')
        {
            pC++;
        }
        if(input == 's')
        {
            pR++;
        }
        if(input == 'w')
        {
            pR--;
        }
        map = setupMap(map, nR, nC, pR, pC);
        printMap(map,nR,nC);
    }
    free(map);
    return 0;
    
}