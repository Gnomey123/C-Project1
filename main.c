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
    char fileDir[LENGTH] = "maze.txt";
  
    //mazeGen(99, 99);
    
    mazeMatrixGen(&fileDir);
    //printMatrix();

    pos_r = 1;
    pos_c = 5;
    
    CWR();
    printf("itchRight=%d , spaces=%d\n",itchRight, spaces);
    //BJPI();
    

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

    //printMatrix();
    
    
    
    
    
    while(alive)
    {
		
	    exploring = 1;
	    while(exploring)
	    {
		
	
	    	if(leftLeastSpace)
	    	{
	    		//*Jump to left*
	    		
	    		
	    		//check if deadend
				if((rightAvl + upAvl + downAvl == 0))
				{
					// *pop and go to last spot and place marker (with backtrace)*
					//*keep going to last spot until mem empty (with backtrace)*
				}

				//check if in intersect
				else if(((leftAvl + upAvl + downAvl > 1))) 
				{
					//*remember pos*
				}
			}
			
			
			if(rightLeastSpace)
	    	{
	    		//*Jump to right*
	    		

	    		
	    		//check if deadend	    		
				if((leftAvl + upAvl + downAvl == 0))
				{
					// *pop and go to last spot and place marker (with backtrace)*
					//*keep going to last spot until mem empty (with backtrace)*
				}

				//check if in intersect
				else if(((leftAvl + upAvl + downAvl > 1))) 
				{
					//*remember pos*
				}
			}
			
			
			if(upLeastSpace)
	    	{
				//*Jump up*

				
	    		//check if deadend				
				if((rightAvl + leftAvl + downAvl == 0))
				{
					
					// *pop and go to last spot and place marker (with backtrace)*
					//*keep going to last spot until mem empty (with backtrace)*
				} 

				//check if in intersect
				else if(((rightAvl + leftAvl + downAvl > 1))) 
				{
					//*remember pos*
				}
			}
			
			
			if(downLeastSpace)
	    	{
	    		//*Jump down*
	
	
				
	    		//check if deadend				
				if((rightAvl + upAvl + downAvl == 0))
				{
					// *pop and go to last spot and place marker (with backtrace)*
					//*keep going to last spot until mem empty (with backtrace)*
				}
				
				//check if in intersect
				else if(((rightAvl + upAvl + downAvl > 1))) 
				{
					//*remember pos*
				}
			}
			
		} // not exploring anymore
	    
	
		}
	}
    
}
