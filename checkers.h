#ifndef CHECKERS_H
#define CHECKERS_H

int validatePW(int nR, int nC, int pR, int pC, char input);
int validatePX(int** Xs, int nR, int nC, int pR, int pC, char input);
int winCond(int pR, int pC, int gR, int gC);
int loseCond(int pR, int pC, int gR, int gC, int nR, int nC, char** map, int** Xs);

#endif