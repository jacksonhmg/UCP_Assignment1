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
    for(i=0;i<nR;i++)
    {
        for(j=0;j<nC;j++)
        {
                printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

void playerInput(int* pR, int* pC, int nR, int nC, int** Xs)
{
    char input;
    int check;
    disableBuffer();
    scanf(" %c",&input);
    enableBuffer();
    if(input == 'a')
    {
        check = validatePW(nR, nC, *pR, *pC, input) && validatePX(Xs,nR,nC,*pR,*pC,input);
        if(check){
            #ifdef BORDERLESS
                if((*pC-1) == 0)
                {
                    (*pC) = nC-1;
                }
            #endif
            if(!((*pC)-1 == 0))
            {
                (*pC)--;
            }
            
        }
    }
    if(input == 'd')
    {
        check = validatePW(nR, nC, *pR, *pC, input) && validatePX(Xs,nR,nC,*pR,*pC,input);
        if(check){
            (*pC)++;
        }    
    }
    if(input == 's')
    {
        check = validatePW(nR, nC, *pR, *pC, input) && validatePX(Xs,nR,nC,*pR,*pC,input);
        if(check){
            (*pR)++;
        }  
    }
    if(input == 'w')
    {
        check = validatePW(nR, nC, *pR, *pC, input) && validatePX(Xs,nR,nC,*pR,*pC,input);
        if(check){
            (*pR)--;
        }
    }
}

int xUpdate(int** Xs, int nR, int nC,int pR, int pC, int gR, int gC)
{
    int xR, xC,i,check;
    do
    {
        check = 1;
        xR = randoms(1,nR-2);
        xC = randoms(1,nC-2);
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == xR) && (Xs[i][1] == xC))
            {
                check = 0;
            }
        }
        if((xR == pR) && (xC == pC))
        {
            check = 0;
        }
        if((xR == gR) && (xC == gC))
        {
            check = 0;
        }
        if(check)
        {
            for(i=0;i<(nR*nC);i++)
            {
                if((Xs[i][0] == 0) && (Xs[i][1] == 0))
                {
                    Xs[i][0] = xR;
                    Xs[i][1] = xC;
                    return 1;
                }
            }
        }
    }while(!check);
    return 0;
}
