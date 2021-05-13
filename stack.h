/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
#include "config.h"
/**
 * Pushes locaiton to mem.
 *
 * Adds pos_r and pos_c to the Memory stack
 */
void push();

/**
 * Retrieves location and Pops it from mem.
 *
 * Adds rememembered locaiton to mem_r and mem_c respectfully, then removed it from the stack
 */
void pop();

/**
 * Retrieves location and keeps it in mem.
 *
 * Adds rememembered locaiton to mem_r and mem_c respectfully
 */
void peek();

/**
 * Kills every memeory of its family and desire to live
 *
 * flushes the memeory stack
 */
void clear();

/**
 * Reports if memeory is full
 *
 * @return 1 for full memeroy, 0 for space avalible
 */
int full();

/**
 * Reports if memeory is empty
 *
 * @return 1 for completely empty mem, 0 for still remembering famuily 
 */
int empty();
extern int top;
extern int stack[STACK_SIZE][2];
