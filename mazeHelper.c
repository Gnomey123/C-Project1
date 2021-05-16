#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "config.h"
#include "Michael.h"
#include "main.h"

FILE *mazeFile;

char maze[LENGTH][LENGTH];
int maxRows = 0, maxCols = 0;

void setMazeChar(int row, int col, char c)
{
	maze[row][col] = c;
}

char getMazeChar(int row, int col)
{
	return maze[row][col];
}

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
	char temp = maze[getPos_r()][getPos_c()];
	maze[getPos_r()][getPos_c()] = 'A';
	
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
	
	maze[getPos_r()][getPos_c()] = temp;
}

void placeMarker(int r, int c)
{
	maze[r][c] = getMarkerChar();
}



int CW_R(int r, int c)
{
	char charPosition = maze[r][c];
	int spacesAvalible = 0;
	int itch;
	//printf("DEBUG: char=%c\n", charPosition);
	
	if(maze[r][c] == getWallChar())
	{
		printf("\n[ERROR]: Somehow CW\'d in a wall? (%d|%d)", r, c);
	}
	
	if(maze[r][c+1] == getWallChar())
	{
		return 0;
	}
	
	
	while((charPosition == getOpenSpaceChar()) || (charPosition == getGoldChar()) || (charPosition == getGoldCollectedChar())) 
	{
		c++;
		charPosition = maze[r][c];
		
		if(charPosition == getWallChar())
		{
			setSpaces(spacesAvalible);
			return 1;	
		}
		else if(charPosition == getMarkerChar())
		{
			return 0;
		}
		else
		{
			spacesAvalible++;	
		}
			
	}
		
		
}


int CW_L(int r, int c)
{
	char charPosition = maze[r][c];
	int spacesAvalible = 0;
	int itch;
	//printf("DEBUG: char=%c\n", charPosition);

	if(maze[r][c] == getWallChar())
	{
		printf("\n[ERROR]: Somehow CW\'d in a wall? (%d|%d)", r, c);
	}	
	
	if(maze[r][c-1] == getWallChar())
	{
		return 0;
	}
	
	while((charPosition == getOpenSpaceChar()) || (charPosition == getGoldChar()) || (charPosition == getGoldCollectedChar())) 
	{
		c--;
		charPosition = maze[r][c];
		
		if(charPosition == getWallChar())
			{
				setSpaces(spacesAvalible);
				return 1;	
			}
			else if(charPosition == getMarkerChar())
			{
				return 0;
			}
			else
			{
				spacesAvalible++;	
			}
		
		
	}
	
	
	
}

int CW_U(int r, int c)
{
	char charPosition = maze[r][c];
	int spacesAvalible = 0;
	int itch;
	//printf("DEBUG: char=%c\n", charPosition);

	if(maze[r][c] == getWallChar())
	{
		printf("\n[ERROR]: Somehow CW\'d in a wall? (%d|%d)", r, c);
	}
	
	if(maze[r-1][c] == getWallChar())
	{
		return 0;
	}	
	
	while((charPosition == getOpenSpaceChar()) || (charPosition == getGoldChar()) || (charPosition == getGoldCollectedChar())) 
	{
		r--;
		charPosition = maze[r][c];
		
		if(charPosition == getWallChar())
		{
			setSpaces(spacesAvalible);
			return 1;	
		}
		else if(charPosition == getMarkerChar())
		{
			return 0;
		}
		else
		{
			spacesAvalible++;	
		}		
		
	}
	
	
}

int CW_D(int r, int c)
{
	char charPosition = maze[r][c];
	int spacesAvalible = 0;
	int itch;
	//printf("DEBUG: char=%c\n", charPosition);

	if(maze[r][c] == getWallChar())
	{
		printf("\n[ERROR]: Somehow CW\'d in a wall? (%d|%d)", r, c);
	}
		
	if(maze[r+1][c] == getWallChar())
	{
		return 0;
	}	
	
	while((charPosition == getOpenSpaceChar()) || (charPosition == getGoldChar()) || (charPosition == getGoldCollectedChar())) 
	{
		r++;
		charPosition = maze[r][c];

		if(charPosition == getWallChar())
		{
			setSpaces(spacesAvalible);
			return 1;	
		}
		else if(charPosition == getMarkerChar())
		{
			return 0;
		}
		else
		{
			spacesAvalible++;	
		}		
		
		
	}
	
}

/*******



*******/





