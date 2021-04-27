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


    
  
    
    mazeMatrixGen();
    
    CW_R(7,4);
    
    CW_L(1,19);
    
    CW_U(3,1);
    
    CW_D(5,23);
    
    printf("itchRight: %d\n", Michael.itchRight);
    printf("itchLeft: %d\n", Michael.itchLeft);
    printf("itchUp: %d\n", Michael.itchUp);
    printf("itchDown: %d\n", Michael.itchDown);
    
    
   
    push(10, 13);
    printf("\n\nMem before push: %d|%d\n", Michael.mem_x, Michael.mem_y);
    
    
    peek();
     
    printf("Mem after peek#1: %d|%d\n", Michael.mem_x, Michael.mem_y);
     
    push(25, 55);
    peek();
    printf("Mem after peek#2: %d|%d\n", Michael.mem_x, Michael.mem_y);
    
    pop();
    printf("Mem after pop: %d|%d\n", Michael.mem_x, Michael.mem_y);
    peek();
    printf("Mem after peek#3: %d|%d\n", Michael.mem_x, Michael.mem_y);
}
