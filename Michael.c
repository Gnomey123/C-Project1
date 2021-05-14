#include "stack.h"
#include "config.h"
#include "mazeHelper.h"
#include <stdio.h>

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

//  the ant marks its current position using a chemical called pheromone.
void MARK()
{
	consume(3);
	placeMarker(pos_r, pos_c);
}

// the ant is oriented weirdly. I would suggest taking it to the prof to proofcheck
//  moves ANT one position forward.
//  i.e. If Michael locates in (x, y), it will move to (x + 1, y). 
void MOVE_L()
{
	consume(3);
	pos_c--;
}

//  moves ANT one position backward.
//  i.e. If Michael locates in (x, y), it will move to (x - 1, y). 
void MOVE_R()
{
	consume(3);
	pos_c++;
}

//  moves ANT one position to the left.
//  i.e. If Michael locates in (x, y), it will move to (x, y + 1). 
void MOVE_U()
{
	consume(3);
	pos_r--;
}

//  moves ANT one position to the right.
//  i.e. If Michael locates in (x, y), it will move to (x, y - 1). 
void MOVE_D()
{
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

	CW_L(pos_r, pos_c);

	itchUp=0;
	itchDown=0;
	itchRight=0;
}

// same as the func before but to the right
void CWR()
{
	consume(1);

	CW_R(pos_r, pos_c);

	itchUp=0;
	itchDown=0;
	itchLeft=0;
}

// up
void CWU()
{
	consume(1);

	CW_U(pos_r, pos_c);

	itchDown=0;
	itchLeft=0;
	itchRight=0;
}

// down
void CWD()
{
	consume(1);

	CW_D(pos_r, pos_c);

	itchUp=0;
	itchLeft=0;
	itchRight=0;
}

//  pushes the planar coordinates x and y of Michael’s current position into Michael’s
//  stack for the memory. This way Michael memorizes the current position.
void PUSH()
{
	consume(4);

	push(pos_r, pos_c);
}

// pops the planar coordinates x and y from the top of the Michael’s stack for the
// memory. This way Michael remembers the position, but then it immediately forgets the
// position too. 
//  the issue with this is that we need the function to return 2 variables, but how? I want to use struct but the problem is we need the struct to be global, so that the main program can interact. i guess that we need to make a separate c file for handling data types like struct and stuff

//update (from NOAM): the pop command already deals with this by adding the popped values to mem_r and mem_c respectfully. PEEK also does this
void POP()
{
	consume(4);
	
	pop(&mem_r, &mem_c);
}

// peeks the planar coordinates x and y from the top of the Michael’s stack for the
// memory. This way Michael remembers the position, but does not forget the position. 
// same issue as POP()
void PEEK()
{
	consume(2);

	pop(&mem_r, &mem_c);
}

// micheal clear stack. this is all there is to say.
void CLEAR()
{
	consume(2);

	clear();
	mem_r=0;
	mem_c=0;
}

// bold jump for itching. i am not gonna compy paste it because too large so heres tldr version
// will execute only when feeling itch. then jump to (pos_x + x) and (pos_y + y) position. This will remove itch, so itch boolean to false
void BJPI()
{
	consume(5);
	
	if((itchLeft+itchRight+itchUp+itchDown) > 1)
	{
		printf("\n[ERROR] Jump called w/ multible Itches\n");
		return;
	}
	if((itchLeft+itchRight+itchUp+itchDown) == 0)
	{
		printf("\n[ERROR] Jump called w/ no Itches\n");
		return;
	}
	
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

}
// same but will only jump to (pos_x +- 1) and (pos_y +- 1) position. determine which way to move
void CJPI()
{
	consume(3);

	if((itchLeft+itchRight+itchUp+itchDown) > 1)
	{
		printf("\n[ERROR] Jump called w/ multible Itches\n");
		return;
	}
	
	if((itchLeft+itchRight+itchUp+itchDown) == 0)
	{
		printf("\n[ERROR] Jump called w/ no Itches\n");
		return;
	}
	
	if(itchUp == 1)
	{
		spaces--;
	}
	else if(itchDown == 1)
	{
		pos_r++;
	}
	else if(itchLeft == 1)
	{
		pos_c--;
	}
	else if(itchRight == 1)
	{
		pos_c++;
	}

}

//	backtracks to the position that is retrieved from the memory, such as using POP or PEEK.
//	Example: Michael executes a pop and finds the position <4,4>. Backtrack will move Michael back to this position
void BACKTRACK()
{
	consume(2); //(NOAM) not sure if it should consume energy (prof seems to forget it exists). I simply put 6 case its part of 69 hehe gottem
				//edit: 2 makes more sense when thinking about the fact that Poping takes 4 energy
	
	pos_r = mem_r;
	pos_c = mem_c;
	
	
}

// func that consumes energy.
void consume(int cost)
{
	energy -= cost;
}

//	kills the ant. should be implemented in the main() function to avoid interferences.
//	Returns 0 (false) if energy not depleted (greater than 0). Else log state and return 1 (true)
int killCommand()
{
	if(energy > 0)
	{
		return 0;
	}
	else
	{
		printf("Michael has died.\n");
		/*
			insert output log
			puts(outputLogFile, "\nMicheal has died. Program terminated.");	//	when file logging is made this will be important?
		*/
		return 1;
	}
	
}