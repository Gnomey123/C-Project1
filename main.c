// struct main
// {
    
// };
#include <stdio.h>
#include "Michael.h"
#include "mazeHelper.h"
#include "stack.h"
#include "config.h"
#include "mazegen/mazeGen.h"



int main()
{
    int x, y;
	//char *fileDir = "maze_environment.txt";

    char *fileDir = "maze.txt";
  
    mazeGen(99, 99);
    
    mazeMatrixGen(fileDir);
    printMatrix();

    pos_r = 7;
    pos_c = 4;
    
    CWR();
    
    BJPI();
    
    
   /* if(x=1)
    {
    	/CW_R(r, c);
    	
    	
	}
	*/
}
