#include <stdio.h>
#include <ctype.h>
#include "mazeHelper.h"
#include "config.h"
#define LENGTH 256

FILE *maze;

void open()
{
	maze = fopen("maze_environment.txt", "r+");
}

void close()
{
	fclose(maze);
}


int getMazeRows()
{
	int rows = 0;
	char str[LENGTH];
	open();
	while(fscanf(maze, "%s\n", &str) != EOF)
	{
		rows++;
	}
	return rows;

}

void placeChar(int x, int y, char c)
{

}
