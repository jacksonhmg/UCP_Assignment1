#ifndef GAMELOOP_H
#define GAMELOOP_H

void printMap(char** map, int nR, int nC);
void playerInput(int* pR, int* pC, int nR, int nC, int** Xs);
int xUpdate(int** Xs, int nR, int nC, int pR, int pC, int gR, int gC);

#endif