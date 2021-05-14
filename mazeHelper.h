#include <stdio.h>
#include "config.h"
/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
extern int itchDown;
void CW_D(int r,int c);
extern int itchUp;
void CW_U(int r,int c);
extern int itchLeft;
void CW_L(int r,int c);
extern int itchRight;
extern int spaces;
void CW_R(int r,int c);
void placeMarker(int r,int c);
extern int pos_c;
extern int pos_r;
void viewMapMatrix();
void printMatrix();
void mazeMatrixGen(char *fileDir);
int getMax_y();
int getMax_x();
extern int maxRows;
extern char maze[LENGTH][LENGTH];
extern FILE *mazeFile;
