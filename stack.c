//idk copy paste??
// stack ADT
// stack of integers

#include <stdio.h>

#define  STACK_SIZE    100

// variables of the stack ADT
int stack [STACK_SIZE];      // 1D array
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
int topf () {
	
	return stack [ top - 1];
}

int pop () {
	int aux;
	
	aux = stack [ top - 1];
	
	top--;                        // changes the top of the stack; removes the value on top
	
	return aux;
}

void push (int value) {
	
	stack [ top ] = value;
	top++;
	
} 