#ifndef GAMELOOP_H
#define GAMELOOP_H

void printMap(char** map, int nR, int nC);
int playerInput(int* pR, int* pC, int nR, int nC, char** map);
void xUpdate(char** map, int nR, int nC);
void optionsPrint();

#endif