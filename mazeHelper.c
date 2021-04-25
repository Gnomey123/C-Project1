#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "mazeHelper.h"
#include "config.h"
#include "antStruct.h"
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
void mazeMatrixGen()
{
	int row = 0, col = 0;
	char c;
	
	mazeFile = fopen("maze_environment.txt", "r+");
	
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
	
	maxRows = row - 1;
	
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

void placeMarker(int r, int c)
{
	maze[r][c] = '?';
}

int spacesFree(int r, int c, int direction) // direction key: 1=Up, 2=Right, 3=Down, 4=Left
{
	int spaces = 0;
	switch (direction)
	{
		case 1:
			while ((maze[r-1][c] == '*') || (maze[r-1][c] == '$') || (maze[r-1][c] == '@'))
			{
				spaces++;
				r--;
			}
			break;
		case 2:
			while ((maze[r][c+1] == '*') || (maze[r][c+1] == '$') || (maze[r][c+1] == '@'))
			{
				spaces++;
				c++;
			}
			break;
		case 3:
			while ((maze[r+1][c] == '*') || (maze[r+1][c] == '$') || (maze[r+1][c] == '@'))
			{
				spaces++;
				r++;
			}
			break;
		case 4:
			while ((maze[r][c-1] == '*') || (maze[r][c-1] == '$') || (maze[r][c-1] == '@'))
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
		case '*':
			Michael.itchRight = spacesFree(r, c, 2);
			break;
		case '@':
			Michael.itchRight = spacesFree(r, c, 2);
			break;
		case '$':
			Michael.itchRight = spacesFree(r, c, 2);
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
		case '*':
			Michael.itchLeft = spacesFree(r, c, 4);
			break;
		case '@':
			Michael.itchLeft = spacesFree(r, c, 4);
			break;
		case '$':
			Michael.itchLeft = spacesFree(r, c, 4);
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
		case '*':
			Michael.itchUp = spacesFree(r, c, 1);
			break;
		case '@':
			Michael.itchUp = spacesFree(r, c, 1);
			break;
		case '$':
			Michael.itchUp = spacesFree(r, c, 1);
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
		case '*':
			Michael.itchDown = spacesFree(r, c, 3);
			break;
		case '@':
			Michael.itchDown = spacesFree(r, c, 3);
			break;
		case '$':
			Michael.itchDown = spacesFree(r, c, 3);
			break;
		default:
			printf("\n[WARNING] CW called at illegal location: (%d|%d)\n");
			break;
	}
}




