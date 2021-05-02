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
placeMarker(pos_r, pos_c);
}

// the ant is oriented weirdly. I would suggest taking it to the prof to proofcheck
//  moves ANT one position forward.
//  i.e. If Michael locates in (x, y), it will move to (x + 1, y). 
void MOVE_F()
{

}

//  moves ANT one position backward.
//  i.e. If Michael locates in (x, y), it will move to (x - 1, y). 
void MOVE_B()
{

}

//  moves ANT one position to the left.
//  i.e. If Michael locates in (x, y), it will move to (x, y + 1). 
void MOVE_L()
{

}

//  moves ANT one position to the right.
//  i.e. If Michael locates in (x, y), it will move to (x, y - 1). 
void MOVE_R()
{

}

//– Michael checks if the next locations (until meeting a wall) to the left are pheromone
// free. If the locations are free then Michael feels an itch. Otherwise, if no location is free
// (e.g., because there is a pheromone mark or a wall on the left of Michael), then Michael
// does not feel the itch. 
void CWL()
{
CW_L(pos_r, pos_c);

itchUp=0;
itchDown=0;
itchRight=0;
}

// same as the func before but to the right
void CWR()
{
CW_R(pos_r, pos_c);

itchUp=0;
itchDown=0;
itchLeft=0;
}

// up
void CWU()
{
CW_U(pos_r, pos_c);

itchDown=0;
itchLeft=0;
itchRight=0;
}

// down
void CWD()
{
CW_D(pos_r, pos_c);

itchUp=0;
itchLeft=0;
itchRight=0;
}

//  pushes the planar coordinates x and y of Michael’s current position into Michael’s
//  stack for the memory. This way Michael memorizes the current position.
void PUSH()
{
push(pos_r, pos_c);
}

// pops the planar coordinates x and y from the top of the Michael’s stack for the
// memory. This way Michael remembers the position, but then it immediately forgets the
// position too. 
//  the issue with this is that we need the function to return 2 variables, but how? I want to use struct but the problem is we need the struct to be global, so that the main program can interact. i guess that we need to make a separate c file for handling data types like struct and stuff
void POP()
{
pop(&mem_r, &mem_c);
}

// peeks the planar coordinates x and y from the top of the Michael’s stack for the
// memory. This way Michael remembers the position, but does not forget the position. 
// same issue as POP()
void PEEK()
{
pop(&mem_r, &mem_c);
}

// micheal clear stack. this is all there is to say.
void CLEAR()
{
clear();
mem_r=0;
mem_c=0;
}

// bold jump for itching. i am not gonna compy paste it because too large so heres tldr version
// will execute only when feeling itch. then jump to (pos_x + x) and (pos_y + y) position. This will remove itch, so itch boolean to false
void BJPI()
{
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

}

// same but will only jump to (pos_x +- 1) and (pos_y +- 1) position. determine which way to move
void CJPI()
{

}

// other pograms i guess. im done for the day. bye
