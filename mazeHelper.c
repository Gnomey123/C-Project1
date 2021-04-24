#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "mazeHelper.h"
#include "config.h"
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


