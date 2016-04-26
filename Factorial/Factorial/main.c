//
//  main.c
//  recursion_example1
//
//  Created by Neeraj Kumbhar on 2/16/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

void fact(int x)
{
    for (int i=0; i<x; i++)
    {
        printf("*");
    }
    printf("\n");
    
    if(x>0)
        fact(x-1);
    
    //if(x > 1)
    //    {
    //        x = x * (fact(x-1));
    //    }
    //
    //    return x;
}

int main(int argc, const char * argv[]) {
    
    int n;
    printf("\nEnter a number");
    scanf("%d", &n);
    
    int result = 1, i;
    
    fact(n);
    
    
    // printf("%d", result);
    return 0;
}
