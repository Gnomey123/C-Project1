// struct main
// {
    
// };
#include <stdio.h>
#include "Michael.h"
#include "mazeHelper.h"
#include "stack.h"
#include "config.h"
#include "mazegen/mazeGen.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void rpMan(int *i, int n, int t, int (*scriptData)[3])
{
	int ogI = *i, nScanner, tScanner;
	int command;
	for(nScanner = 0; nScanner < n; nScanner++)
	{
		for(tScanner = 0; tScanner < t-1; tScanner++)
		{
			command = scriptData[ogI + tScanner + 1][0];
				switch(command)
				{
					case 1:
						MARK();
						break;
					case 2:
						MOVE_U();
						break;
					case 3:
						MOVE_D();
						break;
					case 4:
						MOVE_L();
						break;
					case 5:
						MOVE_R();
						break;
					case 6:
						CWL();
						break;
					case 7:
						CWR();
						break;
					case 8:
						CWU();
						break;
					case 9:
						CWD();
						break;
					case 10:
						PUSH();
						break;
					case 11:
						POP();
						break;
					case 12:
						PEEK();
						break;
					case 13:
						CLEAR();
						break;
					case 14:
						BJPI();
						break;
					case 15:
						CJPI();
						break;
					case 16:
						BACKTRACK();
						break;
					case 17:
						printf("\n[ERROR] why you make nested rp so hard\n");
						break;
					default:
						break;
			}
		}
	runTick();
	}
	
	ogI = n + *i;
	*i = ogI;
	
}


int main()
{
    int x, y;
	//char *fileDir = "maze_environment.txt";
    char fileDir[LENGTH] = "maze.txt";
    
    energy = INIT_ENERGY;
  
    //mazeGen(99, 99);
    
    mazeMatrixGen(&fileDir);
    //printMatrix();

    pos_r = 1;
    pos_c = 5;
    
    //CWR();
    //printf("itchRight=%d , spaces=%d\n",itchRight, spaces);
    //BJPI();
    
	FILE *in;
 	
	in = fopen("intelligence.txt", "r");
	
	char str[LENGTH];
	
	int scriptData[LENGTH][3], i = 0, n, t, lenTot;
	
	/*****
	
	scriptDataKey:
	
	1 Mark
	2-5 MOVE
	6-9 CW
	10 PUSH
	11 POP
	12 PEEK
	13 CLEAR
	14 BJPI
	15 CJPI
	16 BACKTRACK
	17 RP n t			NOTE: ARGS exist: [i][0] = 17, [i][1] = n, [i][2] = t
	
	
	******/
	
	
	
	
	
	
	while(fgets(str, 256, in) != NULL)
	{
		
		printf("debug: str=%s\n", str);
		if(strncmp(str, "MARK", 4) == 0)  		{scriptData[i][0]=1;}
		else if(strncmp(str, "MOVE_F", 6) == 0)	{scriptData[i][0]=2;}
		else if(strncmp(str, "MOVE_B", 6) == 0)	{scriptData[i][0]=3;}
		else if(strncmp(str, "MOVE_L", 6) == 0)	{scriptData[i][0]=4;}
		else if(strncmp(str, "MOVE_R", 6) == 0)	{scriptData[i][0]=5;}
		else if(strncmp(str, "CWL", 3) == 0)	{scriptData[i][0]=6;}
		else if(strncmp(str, "CWR", 3) == 0)	{scriptData[i][0]=7;}
		else if(strncmp(str, "CWF", 3) == 0)	{scriptData[i][0]=8;}
		else if(strncmp(str, "CWB", 3) == 0)	{scriptData[i][0]=9;}
		else if(strncmp(str, "PUSH", 4) == 0)	{scriptData[i][0]=10;}
		else if(strncmp(str, "POP",3) == 0)		{scriptData[i][0]=11;}
		else if(strncmp(str, "PEEK", 4) == 0)	{scriptData[i][0]=12;}
		else if(strncmp(str, "CLEAR", 5) == 0)	{scriptData[i][0]=13;}
		else if(strncmp(str, "BJPI", 4) == 0)	{scriptData[i][0]=14;}
		else if(strncmp(str, "CJPI", 4) == 0)	{scriptData[i][0]=15;}
		else if(strncmp(str,"BACKTRACE",9)==0)	{scriptData[i][0]=16;}
		
		
		//RP has two args after it, so it is delt with parsing
		else if((strncmp(str, "RP", 2) == 0)  || (strncmp(str, "rp", 2) == 0))
		{
			char* token = strtok(str, " ");
			
			token = strtok(NULL, " ");
			n = atoi(token);
			
			token = strtok(NULL, " ");
			t = atoi(token);
			
			scriptData[i][0]=17;
			scriptData[i][1]=t;
			scriptData[i][2]=n;
			
		}
		else
		{
			i--;
		}

		i++;
	}
	fclose(in);
	lenTot = i;
	for(i = 0; i < lenTot; i++)
	{
		printf("scriptData[%d]= %d %d %d\n", i, scriptData[i][0], scriptData[i][1], scriptData[i][2]);
	}
	
	
	
		int command;
	while(1==1)
	{
		for(i = 0; i < lenTot; i++)
		{
			command = scriptData[i][0];
			switch(command)
			{
				case 1:
					MARK();
					break;
				case 2:
					MOVE_U();
					break;
				case 3:
					MOVE_D();
					break;
				case 4:
					MOVE_L();
					break;
				case 5:
					MOVE_R();
					break;
				case 6:
					CWL();
					break;
				case 7:
					CWR();
					break;
				case 8:
					CWU();
					break;
				case 9:
					CWD();
					break;
				case 10:
					PUSH();
					break;
				case 11:
					POP();
					break;
				case 12:
					PEEK();
					break;
				case 13:
					CLEAR();
					break;
				case 14:
					BJPI();
					break;
				case 15:
					CJPI();
					break;
				case 16:
					BACKTRACK();
					break;
				case 17:
					rpMan(&i, scriptData[i][1], scriptData[i][2], scriptData);
					break;
				default:
					break;
			}
		runTick();
		}
	}
	
	
}
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
    
    
    

	
 	
 	
    

