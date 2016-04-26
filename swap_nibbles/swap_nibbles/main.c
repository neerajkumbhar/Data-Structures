//
//  main.c
//  swap_nibbles
//
//  Created by Neeraj Kumbhar on 3/22/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//
#include <stdio.h> 

unsigned char swap_nibbles(unsigned char c)
{
    unsigned char temp1, temp2;
    
    temp1 = c & 0x0F;
    
    temp2 = c & 0xF0;
    
    temp1=temp1 << 4;
    
    temp2=temp2 >> 4;
    
    printf("\ntemp1  = %d", temp1);
    
    printf("\ntemp2  = %d", temp2);
    
    return(temp2|temp1);
    
    //adding the bits

}

int main(void)
{
    char ch=0x22;
    printf("\nThe exchanged value is %x\n",swap_nibbles(ch));
    
    double a,b;
    if(a==b)
        return 1;
    else
        return 0;
    return 0;
}