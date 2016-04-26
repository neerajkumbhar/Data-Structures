//
//  main.c
//  interger_to_character
//
//  Created by Neeraj Kumbhar on 2/17/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <math.h>


void function(int a, int c)
{
    
    if(c>0)
    {
        int b = a/c;
        printf(" %d ", b);
        function(a%c, c/10);
    }
    
}

int main(int argc, const char * argv[]) {
    
    
    int a  = 324434354;
    char arr[100];
    
    function(a, pow(10,(floor(log10(abs(a))))) );
             
    return 0;
}
