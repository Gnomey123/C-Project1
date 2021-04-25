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
    
    CW_R(7,4);
    
    CW_L(1,19);
    
    CW_U(3,1);
    
    CW_D(5,23);
    
    printf("itchRight: %d\n", Michael.itchRight);
    printf("itchLeft: %d\n", Michael.itchLeft);
    printf("itchUp: %d\n", Michael.itchUp);
    printf("itchDown: %d\n", Michael.itchDown);
}
