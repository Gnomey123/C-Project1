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
    

   /*
   //   I wanna see the ant moving in the maze to make it easier to keep track of our algorithm, so maybe
   while(1)
   {
        if(killCommand())
        {
            break;
        }

        followAlgorithm();   // reads algorithm list (array of commands) and executes functions according to their id

        viewMapMatrix(); // shows the maze with the ant's location (which is why i made it a different )
        sleep(1); // give a chance for the user to see the maze
        Clrscr();    // clears screen, basically animating the process
   }
   */

    printMatrix();
}
