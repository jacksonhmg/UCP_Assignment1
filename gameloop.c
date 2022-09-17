#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "gameloop.h"
#include "terminal.h"
#include "checkers.h"
#include "random.h"


void printMap(char** map, int nR, int nC)
{
    int i,j;
    system("clear");
    for(i=0;i<nR;i++)
    {
        for(j=0;j<nC;j++)
        {
                printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

int playerInput(int* pR, int* pC, int nR, int nC, char** map)
{
    char input;
    int check, valid;
    valid = 0;
    disableBuffer();
    scanf(" %c",&input);
    enableBuffer();
    if(input == 'a')
    {
        check = validatePW(nR, nC, *pR, *pC, input,map) && validatePX(map,nR,nC,*pR,*pC,input);
        if(check){
            #ifdef BORDERLESS
                if((*pC-1) == 0)
                {
                    (*pC) = nC-1;
                }
            #endif
            (*pC)--;
            valid = 1;
        }
    }
    if(input == 'd')
    {
        check = validatePW(nR, nC, *pR, *pC, input,map) && validatePX(map,nR,nC,*pR,*pC,input);
        if(check){
            #ifdef BORDERLESS
                if((*pC+1) == nC-1)
                {
                    (*pC) = 0;
                }
            #endif
            (*pC)++;
            valid = 1;
        }    
    }
    if(input == 's')
    {
        check = validatePW(nR, nC, *pR, *pC, input,map) && validatePX(map,nR,nC,*pR,*pC,input);
        if(check){
            #ifdef BORDERLESS
                if((*pR+1) == nR-1)
                {
                    (*pR) = 0;
                }
            #endif
            (*pR)++;
            valid = 1;
        }  
    }
    if(input == 'w')
    {
        check = validatePW(nR, nC, *pR, *pC, input,map) && validatePX(map,nR,nC,*pR,*pC,input);
        if(check){
            #ifdef BORDERLESS
                if((*pR-1) == 0)
                {
                    (*pR) = nR-1;
                }
            #endif
            (*pR)--;
            valid = 1;
        }
    }
    return valid;
}

void xUpdate(char** map, int nR, int nC)
{
    int xR, xC;
    xR = randoms(1,nR-2);
    xC = randoms(1,nC-2);

    while(map[xR][xC] != ' ')
    {
        xR = randoms(1,nR-2);
        xC = randoms(1,nC-2);
    }
    map[xR][xC] = 'X';
}

void optionsPrint()
{
    printf("Press w to go up\n");
    printf("Press s to go down\n");
    printf("Press a to go left\n");
    printf("Press d to go right\n");
}
