#ifndef GAMELOOP_H
#define GAMELOOP_H

void printMap(char** map, int nR, int nC);
void playerInput(int* pR, int* pC, int nR, int nC);
int xUpdate(int*** Xs, int nR, int nC, int pR, int pC);

#endif