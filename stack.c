//idk copy paste??
// stack ADT
// stack of integers

#include <stdio.h>
#include "Michael.h"
#include "config.h"


// variables of the stack ADT
int stack [STACK_SIZE][2];      // 2D array to store X and Y ints
int top = 0;

// six functions
int empty () {

	return (top == 0)? 1: 0;

} // empty

int full () {
	
	return (top == STACK_SIZE)? 1: 0;

} // full

// empties the stack
void clear () {
	
	top = 0;
	
}

// return the value on the stack's top but does not remove it
void peek () {
	if(empty() == 1)
	{
		printf("\n[ERROR] peeked with emtpy memory!\n");
	}

	else
	{
		mem_r = stack [ top - 1][0];
		mem_c = stack [ top - 1][1];
	}
	
}

void pop () {
	
	if(empty() == 1)
	{
		printf("\n[ERROR] popped with emtpy memory!\n");
	}
	else
	{
	

	mem_r = stack [ top - 1][0];
	mem_c = stack [ top - 1][1];
	
	if(top > 0)
	top--;                        // changes the top of the stack; removes the value on top
	
	}
}

void push () {
	if(full() == 1)
	{
		printf("\n[ERROR] pushed beyond the max STACK_SIZE! (STACK_SIZE = %d) (full = %d)\n", STACK_SIZE, full());
	}
	
	else
	{
	stack[top][0] = pos_r;
	stack[top][1] = pos_c;
	
	top++;
	}

	
} 
