// ant object
struct Ant {
    int pos_x;  //  position value
    int pos_y;
    int energy;
    int itchUp;     //  boolean, specific itch for open space above
    int itchDown;   //  boolean, specific itch for open space downward
    int itchLeft;   //  boolean, specific itch for open space to the left
    int itchRight;  //  boolean, specific itch for open space to the right
} Michael;

//  the ant marks its current position using a chemical called pheromone.
void MARK()
{

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

}

// same as the func before but to the right
void CWR()
{

}

// forward
void CWF()
{

}

// backward
void CWB()
{

}

//  pushes the planar coordinates x and y of Michael’s current position into Michael’s
//  stack for the memory. This way Michael memorizes the current position.
void PUSH()
{

}

// pops the planar coordinates x and y from the top of the Michael’s stack for the
// memory. This way Michael remembers the position, but then it immediately forgets the
// position too. 
//  the issue with this is that we need the function to return 2 variables, but how? I want to use struct but the problem is we need the struct to be global, so that the main program can interact. i guess that we need to make a separate c file for handling data types like struct and stuff
void POP()
{

}

// peeks the planar coordinates x and y from the top of the Michael’s stack for the
// memory. This way Michael remembers the position, but does not forget the position. 
// same issue as POP()
void PEEK()
{

}

// micheal clear stack. this is all there is to say.
void CLEAR()
{

}

// bold jump for itching. i am not gonna compy paste it because too large so heres tldr version
// will execute only when feeling itch. then jump to (pos_x + x) and (pos_y + y) position. This will remove itch, so itch boolean to false
void BJPI()
{

}

// same but will only jump to (pos_x +- 1) and (pos_y +- 1) position. determine which way to move
void CJPI()
{

}

// other pograms i guess. im done for the day. bye