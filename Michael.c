#include "stack.h"
#include "config.h"
#include "mazeHelper.h"
#include <stdio.h>

int pos_r;  //  position value
int pos_c;
int mem_r;  //  positions of the memory when called
int mem_c;
int energy;
int itchUp;     //  (-1: no itch, 0 or above itch w/ spaces: itch w/ spaces avalible) itch for open space above
int itchDown;   //  (-1: no itch, 0 or above itch w/ spaces: itch w/ spaces avalible) itch for open space downward
int itchLeft;   //  (-1: no itch, 0 or above itch w/ spaces: itch w/ spaces avalible) itch for open space to the left
int itchRight; 
int spaces;

//  the ant marks its current position using a chemical called pheromone.
void MARK()
{
	consume(3);
	placeMarker(pos_r, pos_c);
}

// the ant is oriented weirdly. I would suggest taking it to the prof to proofcheck
//  moves ANT one position forward.
//  i.e. If Michael locates in (x, y), it will move to (x + 1, y). 
void MOVE_F()
{
	consume(3);
}

//  moves ANT one position backward.
//  i.e. If Michael locates in (x, y), it will move to (x - 1, y). 
void MOVE_B()
{
	consume(3);
}

//  moves ANT one position to the left.
//  i.e. If Michael locates in (x, y), it will move to (x, y + 1). 
void MOVE_L()
{
	consume(3);
}

//  moves ANT one position to the right.
//  i.e. If Michael locates in (x, y), it will move to (x, y - 1). 
void MOVE_R()
{
	consume(3);
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

	int jumpDir=-1;
	int numItches = 0;

	if (itchUp >= 0) numItches++;
	if (itchDown >= 0) numItches++;
	if (itchLeft >= 0) numItches++;
	if (itchRight >= 0) numItches++;

	if( numItches == 0)
	{
		printf("\n[WARNNING] Bold Jump called with no itches active\n");
		return;
	}
	else if(numItches > 1)
	{
		printf("\n[ERROR] Bold Jump called with multiple itches active\n");
		return;
	}

	jumpDir =( (1*(itchLeft+1)) + (2*(itchRight+1)) + (3*(itchUp+1)) + (4*(itchDown+1)) );
	printf("debug: left=1, right=2, up=3, down=4, jumpDir=[%d]\n", jumpDir);

	antJump(jumpDir, itchLeft, itchDown, itchUp, itchDown);
}

// same but will only jump to (pos_x +- 1) and (pos_y +- 1) position. determine which way to move
void CJPI()
{
	consume(3);

	int jumpDir=-1;
	int numItches = 0;

	if (itchUp >= 0) numItches++;
	if (itchDown >= 0) numItches++;
	if (itchLeft >= 0) numItches++;
	if (itchRight >= 0) numItches++;


	if( numItches == 0)
	{
		printf("\n[WARNNING] Bold Jump called with no itches active\n");
		return;
	}
	else if(numItches > 1)
	{
		printf("\n[ERROR] Bold Jump called with multiple itches active\n");
		return;
	}
	jumpDir =( (1*(itchLeft+1)) + (2*(itchRight+1)) + (3*(itchUp+1)) + (4*(itchDown+1)) );
	printf("debug: left=1, right=2, up=3, down=4, jumpDir=[%d]\n", jumpDir);

	antJump(jumpDir, 1, 1, 1, 1);	//	just one step for the ant
}

// other pograms i guess. im done for the day. bye

//	Ant jump. Also clears itch on whatever direction. This requires the itch to be valid i.e. cannot be into a wall or else bruh
void antJump(int jumpDir, int left, int right, int up, int down)
{
	if(jumpDir == 1)
	{
		pos_c += left;
		itchLeft = 0;
	}
	else if(jumpDir == 2)
	{
		pos_c += right;
		itchRight = 0;
	}
	else if(jumpDir == 3)
	{
		pos_r += up;
		itchUp = 0;
	}
	else if(jumpDir == 4)
	{
		pos_r += down;
		itchDown = 0;
	}
}

//	backtracks to the position that is retrieved from the memory, such as using POP or PEEK.
//	Example: Michael executes a pop and finds the position <4,4>. Backtrack will move Michael back to this position
void BACKTRACK()
{

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