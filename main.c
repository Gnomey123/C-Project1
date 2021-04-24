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

    push(23, 45);
    peek(&x, &y);
    
  
    
    mazeMatrixGen();
    
    printMatrix();
}
