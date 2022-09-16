#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "checkers.h"

int validatePW(int nR, int nC, int pR, int pC, char input, int** Xs)
{
    int valid;
    valid = 1;
    if(input == 'a')
    {
        if(pC-1 == 0)
        {
            valid = 0;

            #ifdef BORDERLESS
                if(validatePX(Xs,nR,nC,pR,nC-1,input))
                {
                    valid = 1;
                }
            #endif
            
        }
    }
    if(input == 'd')
    {
        if(pC+1 == nC-1)
        {
            valid = 0;
            
            #ifdef BORDERLESS
                if(validatePX(Xs,nR,nC,pR,0,input))
                {
                    valid = 1;
                }
            #endif

        }
    }
    if(input == 's')
    {
        if(pR+1 == nR-1)
        {
            valid = 0;
            #ifdef BORDERLESS
                if(validatePX(Xs,nR,nC,0,pC,input))
                {
                    valid = 1;
                }
            #endif

           
        }
    }
    if(input == 'w')
    {
        if(pR-1 == 0)
        {
            valid = 0;
            #ifdef BORDERLESS
                if(validatePX(Xs,nR,nC,nR-1,pC,input))
                {
                    valid = 1;
                }
            #endif
        }
    }
    return valid;
}

int validatePX(int** Xs, int nR, int nC, int pR, int pC, char input)
{
    int i, valid;
    valid = 1;
    if(input == 'a')
    {
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == (pR)) && (Xs[i][1] == (pC-1)))
            {
                valid = 0;
            }
        }
    }
    if(input == 'd')
    {
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == (pR)) && (Xs[i][1] == (pC+1)))
            {
                valid = 0;
            }
        }
    }
    if(input == 's')
    {
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == (pR+1)) && (Xs[i][1] == (pC)))
            {
                valid = 0;
            }
        }
    }
    if(input == 'w')
    {
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == (pR-1)) && (Xs[i][1] == (pC)))
            {
                valid = 0;
            }
        }
    }
    return valid;
}

int winCond(int pR, int pC, int gR, int gC)
{
    return (pR == gR && pC == gC) ? 1 : 0;
}


int loseCond(int pR, int pC, int gR, int gC, int nR, int nC,char** map, int** Xs)
{
    int check = 0;

    /*checking if possible to move at all*/
    if(!(validatePW(nR, nC, pR, pC, 'w',Xs) && validatePX(Xs,nR,nC,pR,pC,'w')) &&
    !(validatePW(nR, nC, pR, pC, 'a',Xs) && validatePX(Xs,nR,nC,pR,pC,'a')) &&
    !(validatePW(nR, nC, pR, pC, 's',Xs) && validatePX(Xs,nR,nC,pR,pC,'s')) && 
    !(validatePW(nR, nC, pR, pC, 'd',Xs) && validatePX(Xs,nR,nC,pR,pC,'d')))
    {
        check = 1;
    }

    /*  checking goal is surrounded by Xs or *'s  */
    if((map[gR-1][gC] == 'X' || map[gR-1][gC] == '*') && 
    (map[gR+1][gC] == '*' || map[gR+1][gC] == 'X') && 
    (map[gR][gC-1] == '*' || map[gR][gC-1] == 'X') && 
    (map[gR][gC+1] == '*' || map[gR][gC+1] == 'X'))
    {
        check = 1;
    }
    return check;
}