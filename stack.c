//idk copy paste??
// stack ADT
// stack of integers

#include <stdio.h>
#include "Michael.h"
#include "config.h"


// variables of the stack ADT
int stack [STACK_SIZE][2];      // 2D array to store X and Y ints
int top = 0;

int getStackTop()
{
	return top;
}

// six functions
int isStackEmpty () {

	return (top == 0)? 1: 0;

} // empty

int isStackFull () {
	
	return (top == STACK_SIZE)? 1: 0;

} // full

// empties the stack
void clearStack () {
	
	top = 0;
	
}

// return the value on the stack's top but does not remove it
void peekStack () {
	if(isStackEmpty() == 1)
	{
		printf("\n[ERROR] peeked with emtpy memory!\n");
	}

	else
	{
		setMem_r(stack [ top - 1][0]);
		setMem_c(stack [ top - 1][1]);
	}
	
}

void popStack() {
	
	if(isStackEmpty() == 1)
	{
		printf("\n[ERROR] popped with emtpy memory!\n");
	}
	else
	{
	

	setMem_r(stack [ top - 1][0]);
	setMem_c(stack [ top - 1][1]);
	
	if(top > 0)
	top--;                        // changes the top of the stack; removes the value on top
	
	}
}

void pushStack() {
	if(isStackFull() == 1)
	{
		printf("\n[ERROR] pushed beyond the max STACK_SIZE! (STACK_SIZE = %d) (full = %d)\n", STACK_SIZE, isStackFull());
	}
	
	else
	{
	stack[top][0] = getPos_r();
	stack[top][1] = getPos_c();
	
	top++;
	}

	
} 
