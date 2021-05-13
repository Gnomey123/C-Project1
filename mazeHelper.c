#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "config.h"
#include "Michael.h"

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



void CW_R(int r, int c)
{
	char charPosition = ' ';
	int spacesAvalible = 0;
	//printf("DEBUG: char=%c\n", charPosition);
	
	
	while((charPosition == ' ') || (charPosition == '@') || (charPosition == '$')) 
	{
		c++;
		charPosition = maze[r][c];
		switch (charPosition)
		{
			case '|':
				spaces = spacesAvalible;
				itchRight = 1;
				return;
			case '#': //if marker is in path, dont make itch
				itchRight = 0;
				spaces = 0;
				return;
			default:
				spacesAvalible++;
		}
		
		
	}
	
	
	
}

void CW_L(int r, int c)
{
	char charPosition = ' ';
	int spacesAvalible = 0;
	//printf("DEBUG: char=%c\n", charPosition);
	
	
	while((charPosition == ' ') || (charPosition == '@') || (charPosition == '$')) 
	{
		c--;
		charPosition = maze[r][c];
		switch (charPosition)
		{
			case '|':
				spaces = spacesAvalible;
				itchLeft = 1;
				return;
			case '#': //if marker is in path, dont make itch
				itchLeft = 0;
				spaces = 0;
				return;
			default:
				spacesAvalible++;
		}
		
		
	}
	
	
	
}

void CW_U(int r, int c)
{
	char charPosition = ' ';
	int spacesAvalible = 0;
	//printf("DEBUG: char=%c\n", charPosition);
	
	
	while((charPosition == ' ') || (charPosition == '@') || (charPosition == '$')) 
	{
		r++;
		charPosition = maze[r][c];
		switch (charPosition)
		{
			case '|':
				spaces = spacesAvalible;
				itchUp = 1;
				return;
			case '#': //if marker is in path, dont make itch
				itchUp = 0;
				spaces = 0;
				return;
			default:
				spacesAvalible++;
		}
		
		
	}
	
	
}

void CW_D(int r, int c)
{
	char charPosition = ' ';
	int spacesAvalible = 0;
	//printf("DEBUG: char=%c\n", charPosition);
	
	
	while((charPosition == ' ') || (charPosition == '@') || (charPosition == '$')) 
	{
		r--;
		charPosition = maze[r][c];
		switch (charPosition)
		{
			case '|':
				spaces = spacesAvalible;
				itchDown = 1;
				
				return;
			case '#': //if marker is in path, dont make itch
				itchDown = 0;
				spaces = 0;
				return;
			default:
				spacesAvalible++;
		}
		
		
	}
	
}

/*******



*******/





