/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
#include "config.h"
void CW_D(int r,int c);
void CW_U(int r,int c);
void CW_L(int r,int c);
void CW_R(int r,int c);
int spacesFree(int r,int c,int direction);
void placeMarker(int r,int c);
void viewMapMatrix();
void printMatrix();
void mazeMatrixGen(char *fileDir);
int getMax_y();
int getMax_x();
extern int maxRows;
extern char maze[LENGTH][LENGTH];
extern FILE *mazeFile;
