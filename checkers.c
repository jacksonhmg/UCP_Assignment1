#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "checkers.h"

int validatePW(int nR, int nC, int pR, int pC, char input)
{
    if(input == 'a')
    {
        if(pC-1 == 0)
        {
            return 0;
        }
    }
    if(input == 'd')
    {
        if(pC+1 == nC-1)
        {
            return 0;
        }
    }
    if(input == 's')
    {
        if(pR+1 == nR-1)
        {
            return 0;
        }
    }
    if(input == 'w')
    {
        if(pR-1 == 0)
        {
            return 0;
        }
    }
    return 1;
}

int validatePX(int** Xs, int nR, int nC, int pR, int pC, char input)
{
    int i;
    if(input == 'a')
    {
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == (pR)) && (Xs[i][1] == (pC-1)))
            {
                return 0;
            }
        }
    }
    if(input == 'd')
    {
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == (pR)) && (Xs[i][1] == (pC+1)))
            {
                return 0;
            }
        }
    }
    if(input == 's')
    {
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == (pR+1)) && (Xs[i][1] == (pC)))
            {
                return 0;
            }
        }
    }
    if(input == 'w')
    {
        for(i=0;i<(nR*nC);i++)
        {
            if((Xs[i][0] == (pR-1)) && (Xs[i][1] == (pC)))
            {
                return 0;
            }
        }
    }
    return 1;
}

int winCond(int pR, int pC, int gR, int gC)
{
    return (pR == gR && pC == gC) ? 1 : 0;
}

int loseCond(int pR, int pC, int gR, int gC, int** Xs, int nR, int nC)
{
    int check, pCounter, gCounter, i;
    check = 0;
    pCounter = 0;
    gCounter = 0;
    for(i=0;i<(nR*nC);i++)
    {
        if((Xs[i][0] == pR-1) && (Xs[i][1] == pC))
        {
            pCounter++;
        }
        if((Xs[i][0] == pR+1) && (Xs[i][1] == pC))
        {
            pCounter++;
        }
        if((Xs[i][0] == pR) && (Xs[i][1] == pC-1))
        {
            pCounter++;
        }
        if((Xs[i][0] == pR) && (Xs[i][1] == pC+1))
        {
            pCounter++;
        }
    }
    if(pCounter == 4)
    {
        check = 1;
    }
    for(i=0;i<(nR*nC);i++)
    {
        if((Xs[i][0] == gR-1) && (Xs[i][1] == gC))
        {
            gCounter++;
        }
        if((Xs[i][0] == gR+1) && (Xs[i][1] == gC))
        {
            gCounter++;
        }
        if((Xs[i][0] == gR) && (Xs[i][1] == gC-1))
        {
            gCounter++;
        }
        if((Xs[i][0] == gR) && (Xs[i][1] == gC+1))
        {
            gCounter++;
        }
    }
    if(gCounter == 4)
    {
        check = 1;
    }
    return check;
}