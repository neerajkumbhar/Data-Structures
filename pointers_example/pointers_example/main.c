//
//  main.c
//  pointers_example
//
//  Created by Neeraj Kumbhar on 31/03/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>


void display(int *k)
{
    printf("\n value = %d", *k);
    
}

int main(int argc, const char * argv[]) {
   
    
    int arr[] = {2,3,9,5,5};
    
    for(int i = 0;i<=4; i++)
        display(&arr[i]);
    
    
    int b= 10;
    printf("\nsixe = %d", sizeof(b));
    
        
    
    
    
    return 0;
}

