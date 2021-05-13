#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "mazeHelper.h"
#include "config.h"
#include "Michael.h"
#define LENGTH 256

FILE *mazeFile;

char maze[LENGTH][LENGTH];
int maxRows = 0, maxCols = 0;


int getMax_x()
{
	return maxRows -1;
}
int getMax_y()
{
	return maxCols -1;
}
void mazeMatrixGen(char *fileDir)
{
	int row = 0, col = 0;
	char c;
	
	mazeFile = fopen(fileDir, "r+");
	
	while((c = getc(mazeFile)) != EOF)
	{
		if(c == '\n')
		{
			row++;
			if(col > maxCols)
			{
				maxCols = col;
			}
			col = 0;
		//	printf("%c", c);
			
		}
		else
		{
			maze[row][col] = c;
			col++; 
		//	printf("%c", c);
		}
		
		
	}
	fclose(mazeFile);
	
	maxRows = row;
	
}

void printMatrix()
{
	printf("maxrows: %d, maxcols: %d\n", maxRows, maxCols);
	int row, col;
	for(row = 0; row < maxRows; row++)
	{
		for(col = 0; col < maxCols; col++)
		{
			printf("%c", maze[row][col]);
		}
		printf("\n");
	}
}

//	same as printMatrix but doesn't show row/col detail and shows ant location
void viewMapMatrix()
{
	int row, col;
	for(row = 0; row < maxRows; row++)
	{
		for(col = 0; col < maxCols; col++)
		{
			if(pos_r == row && pos_c == col)
				printf("A");	// the Antn
			else
				printf("%c", maze[row][col]);
		}
		printf("\n");
	}
}

void placeMarker(int r, int c)
{
	maze[r][c] = '*';
}

int spacesFree(int r, int c, int direction) // direction key: 1=Up, 2=Right, 3=Down, 4=Left NEED TO FIX CW
{
	int spaces = -1;
	int isMarker = 0;
	switch (direction)
	{
		case 1:
			while ((maze[r-1][c] == ' ') || (maze[r-1][c] == '$') || (maze[r-1][c] == '@'))
			{
				spaces++;
				r--;
			}
			break;
		case 2:
			while ((maze[r][c+1] == ' ') || (maze[r][c+1] == '$') || (maze[r][c+1] == '@'))
			{
				spaces++;
				c++;
			}
			break;
		case 3:
			while ((maze[r+1][c] == ' ') || (maze[r+1][c] == '$') || (maze[r+1][c] == '@'))
			{
				
				spaces++;
				r++;
			}
			break;
		case 4:
			while ((maze[r][c-1] == ' ') || (maze[r][c-1] == '$') || (maze[r][c-1] == '@'))
			{
				spaces++;
				c--;
			}
			break;
		default:
			printf("\n[ERROR] illegal spacesFree direction called\n");
			break;
	}
	return spaces;
} 

void CW_R(int r, int c)
{
	char charPosition = maze[r][c];
	
	printf("DEBUG: char=%c\n", charPosition);
	
	
	switch (charPosition)
	{
		case ' ':
			itchRight = spacesFree(r, c, 2);
			break;
		case '@':
			itchRight = spacesFree(r, c, 2);
			break;
		case '$':
			itchRight = spacesFree(r, c, 2);
			break;
		default:
			printf("\n[WARNING] CW called at illegal location: (%d|%d)\n");
			break;
	}
}

void CW_L(int r, int c)
{
	char charPosition = maze[r][c];
	
	printf("DEBUG: char=%c\n", charPosition);
	
	
	switch (charPosition)
	{
		case ' ':
			itchLeft = spacesFree(r, c, 4);
			break;
		case '@':
			itchLeft = spacesFree(r, c, 4);
			break;
		case '$':
			itchLeft = spacesFree(r, c, 4);
			break;
		default:
			printf("\n[WARNING] CW called at illegal location: (%d|%d)\n");
			break;
	}
}

void CW_U(int r, int c)
{
	char charPosition = maze[r][c];
	
	printf("DEBUG: char=%c\n", charPosition);
	
	
	switch (charPosition)
	{
		case ' ':
			itchUp = spacesFree(r, c, 1);
			break;
		case '@':
			itchUp = spacesFree(r, c, 1);
			break;
		case '$':
			itchUp = spacesFree(r, c, 1);
			break;
		default:
			printf("\n[WARNING] CW called at illegal location: (%d|%d)\n");
			break;
	}
}

void CW_D(int r, int c)
{
	char charPosition = maze[r][c];
	
	printf("DEBUG: char=%c\n", charPosition);
	
	
	switch (charPosition)
	{
		case ' ':
			itchDown = spacesFree(r, c, 3);
			break;
		case '@':
			itchDown = spacesFree(r, c, 3);
			break;
		case '$':
			itchDown = spacesFree(r, c, 3);
			break;
		default:
			printf("\n[WARNING] CW called at illegal location: (%d|%d)\n");
			break;
	}
}

/*******



*******/





