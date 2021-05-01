// struct main
// {
    
// };
#include <stdio.h>
#include "antStruct.h"
#include "mazeHelper.h"
#include "stack.h"
#include "config.h"
#include "mazegen/mazeGen.h"



int main()
{
    int x, y;


    
  
    //mazeGen(99, 99);
    
    mazeMatrixGen();
    
    printMatrix();
}
