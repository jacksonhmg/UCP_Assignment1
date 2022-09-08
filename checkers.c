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