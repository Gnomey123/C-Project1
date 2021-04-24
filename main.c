// struct main
// {
    
// };
#include <stdio.h>
#include "antStruct.h"
#include "mazeHelper.h"
#include "stack.h"
#include "config.h"




int main()
{
    int x, y;
	printf("TEST rows: %d\n", getMazeRows());
    push(23, 45);
    peek(&x, &y);
    
    printf("x|y: %d|%d\n", x,y);
}
