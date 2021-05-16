#include "stack.h"
#include "config.h"
#include "Michael.h"
#include "mazeHelper.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

 int pos_r;  //  position value
 int pos_c;
 int mem_r;  //  positions of the memory when called
 int mem_c;
 int energy;
 int itchUp;     //  (0: no itch, 1 itch)
 int itchDown;   //  (0: no itch, 1 itch)
 int itchLeft;   //  (0: no itch, 1 itch)
 int itchRight;  //  (0: no itch, 1 itch)
 int spaces;     // whenever there's an itch, spaces will represnet how much space there is (0 being wall in front, 1+ being spaces to move)
 int gold;       // for the gold collected



	char str[LENGTH]; //usefull for logging
//  the ant marks its current position using a chemical called pheromone.


void quitCode()
{
	logger("\nEND OF SESSION\n");
	viewMapMatrix();
	exit(0);
}

void setEnergy(int e)
{
	energy = e;
}

// func that consumes energy.
void consume(int cost)
{
	energy -= cost;
}

void MARK()
{
	consume(3);
	
	logger("MICHEAL PLACED MARKER AT ");
	
	sprintf(str, "(%d|%d)\n", pos_r, pos_c);
	
	logger(str);
	placeMarker(pos_r, pos_c);
}

void setSpaces(int s)
{
	spaces = s;
}

int getPos_r()
{
	return pos_r;
}

int getPos_c()
{
	return pos_c;
}

int getMem_r()
{
	return mem_r;
}
int getMem_c()
{
	return mem_c;
}


void setPos_r(int r)
{
	pos_r = r;
}

void setPos_c(int c)
{
	pos_c = c;
}

void setMem_r(int r)
{
	mem_r = r;
}

void setMem_c(int c)
{
	mem_c = c;
}

void runTick()
	{
	sprintf(str, "(%c)(%d|%d): ", getMazeChar(pos_r,pos_c),pos_r,pos_c);
	logger(str);
	if(getMazeChar(pos_r,pos_c) == getGoldChar())
	{
		gold++;
		setMazeChar(pos_r, pos_c, getGoldCollectedChar());
		sprintf(str, "GOLD COLLECTED AT (%d|%d) TOT=%d\nDEBUG: energy=&d, topStack=%d\n", pos_r, pos_c, gold, energy, getStackTop());
		logger(str);
	}
	if(energy <= 0)
	{
		sprintf(str, "MICHEAL HAS DIED OF EXHAUSTION AT (%d|%d)\n", pos_r, pos_c);
		logger(str);
		printMatrix();
		quitCode();
		
	}
	if(isStackFull() == 1)
	{
		sprintf(str,  "MICHEAL HAS DIED OF BIG BRAIN ISSUES AT (%d|%d)\n", pos_r, pos_c);
		logger(str);
		printMatrix();
		quitCode();	
	}
	//TODO: add more logggis
	
	
}

void logger(char *str)
{
	FILE *log;
	
	log = fopen("log.txt", "a");
	fprintf(log, str);
	fclose(log);
	
	
}

// the ant is oriented weirdly. I would suggest taking it to the prof to proofcheck
//  moves ANT one position forward.
//  i.e. If Michael locates in (x, y), it will move to (x + 1, y). 
void MOVE_L()
{
	if(getMazeChar(pos_r, pos_c--) == getWallChar())
	{
		printf("[NOTE]: Tried to move Left into a wall\n");
		return;
	}
	sprintf(str, "MOVED LEFT FROM (%d|%d)\n", pos_r, pos_c);
	logger(str);
	consume(3);
	pos_c--;
}

//  moves ANT one position backward.
//  i.e. If Michael locates in (x, y), it will move to (x - 1, y). 
void MOVE_R()
{
	if(getMazeChar(pos_r, pos_c++) == getWallChar())
	{
		printf("[NOTE]: Tried to move Right into a wall\n");
		return;
	}
	
	sprintf(str, "MOVED RIGHT FROM (%d|%d)\n", pos_r, pos_c);
	logger(str);
	
	consume(3);
	pos_c++;
}

//  moves ANT one position to the left.
//  i.e. If Michael locates in (x, y), it will move to (x, y + 1). 
void MOVE_U()
{
		if(getMazeChar(pos_r--, pos_c) == getWallChar())
	{
		printf("NOTE]: Tried to move Up into a wall\n");
		return;
	}

	sprintf(str, "MOVED UP FROM (%d|%d)\n", pos_r, pos_c);
	logger(str);

	consume(3);
	pos_r--;
}

//  moves ANT one position to the right.
//  i.e. If Michael locates in (x, y), it will move to (x, y - 1). 
void MOVE_D()
{
	if(getMazeChar(pos_r++, pos_c) == getWallChar())
	{
		printf("[NOTE]: Tried to move Down into a wall\n");
		return;
	}

	sprintf(str, "MOVED DOWN FROM (%d|%d)\n", pos_r, pos_c);
	logger(str);


	consume(3);
	pos_r++;
	
}

//– Michael checks if the next locations (until meeting a wall) to the left are pheromone
// free. If the locations are free then Michael feels an itch. Otherwise, if no location is free
// (e.g., because there is a pheromone mark or a wall on the left of Michael), then Michael
// does not feel the itch. 
void CWL()
{
	
	consume(1);
	logger("MICHEAL CHECKED LEFT");
	if(1 == CW_L(pos_r, pos_c))
	{
	logger(" AND WAS AVALIBLE (ITCH)\n");
	itchLeft=1;
	itchUp=0;
	itchDown=0;
	itchRight=0;
	}else
	{
		logger(" AND WAS UNAVALIBLE (NO ITCH)\n");
	}


}

// same as the func before but to the right
void CWR()
{


	consume(1);
	logger("MICHEAL CHECKED RIGHT");
	if( 1 == CW_R(pos_r, pos_c))
	{
	logger(" AND WAS AVALIBLE (ITCH)\n");
	itchRight=1;
	itchUp=0;
	itchDown=0;
	itchLeft=0;	
	}else
	{
		logger(" AND WAS UNAVALIBLE (NO ITCH)\n");
	}
	
}

// up
void CWU()
{
	consume(1);
logger("MICHEAL CHECKED FOWARD");
	if( 1 == CW_U(pos_r, pos_c))
	{
	logger(" AND WAS AVALIBLE (ITCH)\n");
	itchUp=1;
	itchDown=0;
	itchLeft=0;
	itchRight=0;
	}else
	{
		logger(" AND WAS UNAVALIBLE (NO ITCH)\n");
	}
		
}

// down
void CWD()
{
	consume(1);
logger("MICHEAL CHECKED BACKWARD");
	if( 1 == CW_D(pos_r, pos_c))
	{
		logger(" AND WAS AVALIBLE (ITCH)\n");
	itchDown=1;
	itchUp=0;
	itchLeft=0;
	itchRight=0;		
	}else
	{
		logger(" AND WAS UNAVALIBLE (NO ITCH)\n");
	}
	


}

//  pushes the planar coordinates x and y of Michael’s current position into Michael’s
//  stack for the memory. This way Michael memorizes the current position.
void PUSH()
{
	consume(4);

	pushStack(pos_r, pos_c);
}

// pops the planar coordinates x and y from the top of the Michael’s stack for the
// memory. This way Michael remembers the position, but then it immediately forgets the
// position too. 
//  the issue with this is that we need the function to return 2 variables, but how? I want to use struct but the problem is we need the struct to be global, so that the main program can interact. i guess that we need to make a separate c file for handling data types like struct and stuff

//update (from NOAM): the pop command already deals with this by adding the popped values to mem_r and mem_c respectfully. PEEK also does this
void POP()
{
	if(isStackEmpty() == 0)
	{	
	return;
	}	
	consume(4);
	popStack();
		
	

}

// peeks the planar coordinates x and y from the top of the Michael’s stack for the
// memory. This way Michael remembers the position, but does not forget the position. 
// same issue as POP()
void PEEK()
{
	if(isStackEmpty() == 0)
	{	
	return;
	}
	consume(2);
	peekStack();
}

// micheal clear stack. this is all there is to say.
void CLEAR()
{
	consume(2);

	clearStack();
	mem_r=0;
	mem_c=0;
}

// bold jump for itching. i am not gonna compy paste it because too large so heres tldr version
// will execute only when feeling itch. then jump to (pos_x + x) and (pos_y + y) position. This will remove itch, so itch boolean to false
void BJPI()
{
	

	
	if((itchLeft+itchRight+itchUp+itchDown) > 1)
	{
		printf("\n[ERROR] Jump called w/ multible Itches\n");
		return;
	}
	if((itchLeft+itchRight+itchUp+itchDown) == 0)
	{
		printf("\n[NOTE] Jump called w/ no Itches\n");
		return;
	}
	
	consume(5);
	if(itchUp == 1)
	{
		while(spaces > 0)
		{
			pos_r--;
			spaces--;
		}
	}
	else if(itchDown == 1)
	{
		while(spaces > 0)
		{
			pos_r++;
			spaces--;
		}	
	}
	else if(itchLeft == 1)
	{
		while(spaces > 0)
		{
			pos_c--;
			spaces--;
		}
	}
	else if(itchRight == 1)
	{
		while(spaces > 0)
		{
			pos_c++;
			spaces--;
		}		
	}
	
	itchLeft=0;
	itchRight=0;
	itchUp=0;
	itchDown=0;

}
// same but will only jump to (pos_x +- 1) and (pos_y +- 1) position. determine which way to move
void CJPI()
{

	
	if((itchLeft+itchRight+itchUp+itchDown) > 1)
	{
		printf("\n[ERROR] Jump called w/ multible Itches\n");
		return;
	}
	
	if((itchLeft+itchRight+itchUp+itchDown) == 0)
	{
		printf("\n[NOTE] Jump called w/ no Itches\n");
		return;
	}
	
	consume(3);
	logger("MICHEAL CJPId");
	if(itchUp == 1)
	{
		pos_r--;
		logger(" FOWARD\n");
	}
	else if(itchDown == 1)
	{
		pos_r++;
		logger(" BACKWARD\n");
	}
	else if(itchLeft == 1)
	{
		pos_c--;
		logger(" LEFT\n");
	}
	else if(itchRight == 1)
	{
		pos_c++;
		logger(" RIGHT\n");
	}
	
	itchLeft=0;
	itchRight=0;
	itchUp=0;
	itchDown=0;

}

//	backtracks to the position that is retrieved from the memory, such as using POP or PEEK.
//	Example: Michael executes a pop and finds the position <4,4>. Backtrack will move Michael back to this position
void BACKTRACK()
{
	
	if((mem_r !=0) &&(mem_c !=0))
	{
		consume(2); //(NOAM) not sure if it should consume energy (prof seems to forget it exists). I simply put 6 case its part of 69 hehe gottem
					//edit: 2 makes more sense when thinking about the fact that Poping takes 4 energy
		
		pos_r = mem_r;
		pos_c = mem_c;
		
		mem_r = 0;
		mem_c = 0;		
	}

	
	
}


